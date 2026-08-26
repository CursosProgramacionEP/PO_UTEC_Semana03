cmake_minimum_required(VERSION 4.3)
project(PO_UTEC_Semana03)

set(CMAKE_CXX_STANDARD 17)

# ---------- Archivos .cpp sueltos en la raíz ----------
file(GLOB RAIZ "${CMAKE_SOURCE_DIR}/*.cpp")
foreach(ARCHIVO ${RAIZ})
    get_filename_component(NOMBRE ${ARCHIVO} NAME_WE)
    add_executable(raiz_${NOMBRE} ${ARCHIVO})
    target_include_directories(raiz_${NOMBRE} PRIVATE ${CMAKE_SOURCE_DIR})
    message(STATUS "Target creado: raiz_${NOMBRE}")
endforeach()

# ---------- Subcarpetas (recursivo) ----------
# Cada carpeta "hoja" que contenga uno o mas .cpp se considera UN solo
# programa: todos sus .cpp se compilan y enlazan juntos (esto permite
# separar una actividad en main.cpp + modulo.h + modulo.cpp). Si la carpeta
# no tiene .cpp propios, simplemente se sigue bajando por sus subcarpetas.
function(agregar_targets_carpeta CARPETA PREFIJO)
    file(GLOB ARCHIVOS_CPP "${CARPETA}/*.cpp")
    file(GLOB ENTRADAS RELATIVE ${CARPETA} ${CARPETA}/*)

    list(LENGTH ARCHIVOS_CPP NUM_CPP)
    if(NUM_CPP GREATER 0)
        add_executable(${PREFIJO} ${ARCHIVOS_CPP})
        target_include_directories(${PREFIJO} PRIVATE ${CARPETA})
        message(STATUS "Target creado: ${PREFIJO}")
    endif()

    foreach(ENTRADA ${ENTRADAS})
        if(IS_DIRECTORY ${CARPETA}/${ENTRADA})
            agregar_targets_carpeta(${CARPETA}/${ENTRADA} ${PREFIJO}_${ENTRADA})
        endif()
    endforeach()
endfunction()

file(GLOB HIJOS RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/*)

foreach(HIJO ${HIJOS})
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${HIJO}
            AND NOT HIJO MATCHES "^\\."
            AND NOT HIJO MATCHES "^cmake-build")

        agregar_targets_carpeta(${CMAKE_SOURCE_DIR}/${HIJO} ${HIJO})

    endif()
endforeach()