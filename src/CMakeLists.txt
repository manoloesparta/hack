file(GLOB hacksrc */*.c)
add_library(hacklib ${hacksrc})
add_executable(comp main.c ${hacksrc})