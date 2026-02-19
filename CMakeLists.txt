cmake_minimum_required(VERSION 4.0)
project(Casamento_de_Padrões C)

set(CMAKE_C_STANDARD 11)

add_executable(TabelaHash "tabelaHash.c" "benchmark/benchmark.c")
add_executable(ForcaBruta "forçaBruta.c" "benchmark/benchmark.c")
add_executable(RabinKarp "rabinKarp.c" "benchmark/benchmark.c")
add_executable(KMP "kmp.c" "benchmark/benchmark.c")
add_executable(BoyerMoore "boyer-moore/bm.c" "benchmark/benchmark.c")
add_executable(BMH "boyer-moore/bmh.c" "benchmark/benchmark.c")
add_executable(BMHS "boyer-moore/bmhs.c" "benchmark/benchmark.c")
