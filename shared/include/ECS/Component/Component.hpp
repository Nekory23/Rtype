/*
** EPITECH PROJECT, 2021
** $
** File description:
** Component
*/

#pragma once

#include "AI.hpp"
#include "Animation.hpp"
#include "Bonus.hpp"
#include "Damage.hpp"
#include "Drawable.hpp"
#include "Event.hpp"
#include "HitBox.hpp"
#include "Position.hpp"
#include "Sound.hpp"
#include "Velocity.hpp"
#include "Vie.hpp"
#include "Weapon.hpp"
#include "WeaponList.hpp"

/*
#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "Asset/Container.hpp"
#include "Network/Packet.hpp"

namespace Component {
    class AI {
        public:
            enum class Strat {
                RunIn,
                Safe,
                Forward,
                Static
            };

            AI(Strat _strat = Strat::Static);
            ~AI() = default;

            Strat strat;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const AI::Strat _strat);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, AI::Strat &_strat);
    srd::net::Packet &operator<<(srd::net::Packet &_packet, const AI &_ai);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, AI &_ai);

    class Animation {
        public:
            Animation(sf::Vector2u _tsize = sf::Vector2u(0, 0),
                sf::Vector2u _ntsize = sf::Vector2u(0, 0), sf::Vector2u _act = sf::Vector2u(0, 0),
                float _time = 1.f, bool _run = false);
            ~Animation() = default;

            sf::Vector2u tsize;
            sf::Vector2u ntsize;
            sf::Vector2u act;
            float time;
            bool run;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Animation &_anim);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Animation &_anim);

    namespace AnimationType {
        class OnDeath : public Animation {
            public:
                OnDeath(sf::Vector2u _tsize = sf::Vector2u(0, 0),
                    sf::Vector2u _ntsize = sf::Vector2u(0, 0), sf::Vector2u _act = sf::Vector2u(0, 0),
                    float _time = 1.f, bool _run = false);
                ~OnDeath() = default;
        };

        class OnSpwan : public Animation {
            public:
                OnSpwan(sf::Vector2u _tsize = sf::Vector2u(0, 0),
                    sf::Vector2u _ntsize = sf::Vector2u(0, 0), sf::Vector2u _act = sf::Vector2u(0, 0),
                    float _time = 1.f, bool _run = false);
                ~OnSpwan() = default;
        };

        class Continue : public Animation {
            public:
                Continue(sf::Vector2u _tsize = sf::Vector2u(0, 0),
                    sf::Vector2u _ntsize = sf::Vector2u(0, 0), sf::Vector2u _act = sf::Vector2u(0, 0),
                    float _time = 1.f, bool _run = false);
                ~Continue() = default;
        };
    }

    class Bonus {
        public:
            enum class Type {
                FireUp = 0,
                DmgUp,
                Heal,
                NewWeapon
            };

            Bonus(Type _type = Type::FireUp, bool _used = false);
            ~Bonus() = default;

            Type type;
            bool used;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Bonus::Type _type);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Bonus::Type &_type);
    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Bonus &_bonus);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Bonus &_bonus);


    class Damage {
        public:
            Damage(uint8_t _dmg = 0.f);
            ~Damage() = default;

            uint8_t dmg;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Damage &_damage);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Damage &_damage);

    class Drawable {
        public:
            Drawable() = default;
            Drawable(const srd::asset::Container &_container, std::size_t _id = 0);
            ~Drawable() = default;

            sf::Sprite sprite;
            std::size_t id = 0;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Drawable &_drawable);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Drawable &_drawable);

    class Event {
        public:
            enum class Action {
                MoveRight,
                MoveLeft,
                MoveUp,
                MoveDown,
                Fire
            };

            Event(std::map<sf::Keyboard::Key, Action> &_map = std::map<sf::Keyboard::Key, Action>());
            ~Event() = default;

            std::map<sf::Keyboard::Key, Action> map;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Event::Action _action);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Event::Action &_action);
    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Event &_event);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Event &_event);

    class HitBox {
        public:
            HitBox(sf::Vector2f _size = sf::Vector2f(0, 0));
            ~HitBox() = default;

            sf::Vector2f size;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const HitBox &_hitbox);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, HitBox &_hitbox);

    class Position {
        public:
            Position(sf::Vector2f _pos = sf::Vector2f(0, 0));
            ~Position() = default;

            sf::Vector2f pos;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Position &_position);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Position &_position);

    class Sound {
        public:
            Sound() = default;
            Sound(const srd::asset::Container &_container, std::size_t _id = 0);
            virtual ~Sound() = default;

            std::size_t id;
            std::shared_ptr<sf::Music> sound;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Sound &_sound);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Sound &_sound);

    namespace SoundType {
        class OnDeath : public Sound {
            public:
                OnDeath() = default;
                OnDeath(const srd::asset::Container &_container, std::size_t _id = 0);
                ~OnDeath() = default;
        };

        class OnSpwan : public Sound {
            public:
                OnSpwan() = default;
                OnSpwan(const srd::asset::Container &_container, std::size_t _id = 0);
                ~OnSpwan() = default;
        };

        class Continue : public Sound {
            public:
                Continue() = default;
                Continue(const srd::asset::Container &_container, std::size_t _id = 0);
                ~Continue() = default;
        };
    }

    class Velocity {
        public:
            Velocity(sf::Vector2f _dir = sf::Vector2f(0, 0), float _speed = 0);
            ~Velocity() = default;

            sf::Vector2f dir;
            float speed;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Velocity &_velocity);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Velocity &_velocity);

    class Vie {
        public:
            Vie(float _pv = 0.f);
            ~Vie() = default;

            float pv;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Vie &_vie);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Vie &_vie);

    class Weapon {
        public:
            enum class Type {
                Simple,
                Big,
                Fast,
                Focus
            };

            Weapon(Type _type = Type::Simple, float _as = 0.f);
            ~Weapon() = default;

            Type type;
            float as;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Weapon::Type _type);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Weapon::Type &_type);
    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Weapon &_weapon);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Weapon &_weapon);

    class WeaponList {
        public:
            WeaponList(std::vector<std::size_t> &_list);
            ~WeaponList() = default;

            std::vector<std::size_t> list;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const WeaponList &_lweapon);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, WeaponList &_lweapon);
}
*/