/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Event
*/

#include "ECS/Component/Event.hpp"

namespace srd::ECS {
     srd::net::Packet &operator<<(srd::net::Packet &_packet, const ActionType &_action)
     {
          _packet << static_cast<uint8_t>(_action);
          return _packet;
     }

     srd::net::Packet &operator>>(srd::net::Packet &_packet, ActionType &_action)
     {
          uint8_t action = 0;

          _packet >> action;
          _action = static_cast<ActionType>(action);
          return _packet;
     }

     namespace Component {
          Event::Event(Map &_map)
               : map(_map)
          {}

          srd::net::Packet &operator<<(srd::net::Packet &_packet, const Event &_event)
          {
               _packet << _event.map;
               return _packet;
          }

          srd::net::Packet &operator>>(srd::net::Packet &_packet, Event &_event)
          {
               _packet >> _event.map;
               return _packet;
          }
     }
}