file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${QueueList} STATIC ${srcs} ${hdrs}) 


