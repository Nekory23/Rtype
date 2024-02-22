include_directories(shared/include)

# include(shared/include/ECS/component.cmake)
# include(shared/src/ECS/component.cmake)
# include(shared/src/ECS/system.cmake)

set(SHARED_SRC
    shared/src/Asset/Container.cpp
    shared/src/Asset/Exception.cpp
#     shared/src/ECS/Entity.cpp
#     shared/src/ECS/EventQueue.cpp
#     shared/src/ECS/Manager.cpp
#     shared/src/Network/Exception.cpp
#     shared/src/Network/Header.cpp
#     shared/src/Network/Packet.cpp
    shared/src/Exception.cpp
#     ${SHARED_COMP_SRC}
#     ${SHARED_SYS_SRC}
)

set(SHARED_HDR
    shared/include/Asset/Container.hpp
    shared/include/Asset/Exception.hpp
#     shared/include/ECS/Action.hpp
#     shared/include/ECS/Container.hpp
#     shared/include/ECS/Container.inl
#     shared/include/ECS/Entity.hpp
#     shared/include/ECS/Event.hpp
#     shared/include/ECS/EventQueue.hpp
#     shared/include/ECS/Manager.hpp
#     shared/include/ECS/Registry.hpp
#     shared/include/ECS/Registry.inl
#     shared/include/Network/Exception.hpp
#     shared/include/Network/Header.hpp
#     shared/include/Network/Packet.hpp
#     shared/include/Network/Packet.inl
    shared/include/Exception.hpp
#     ${SHARED_COMP_HDR}
#     ${SHARED_SYS_HDR}
)