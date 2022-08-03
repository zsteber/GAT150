#include "InputSystem.h"
#include <SDL.h>
#include <iostream>

namespace neu {

    const uint32_t key_space = SDL_SCANCODE_SPACE;
    extern const uint32_t key_up = SDL_SCANCODE_UP;
    extern const uint32_t key_down = SDL_SCANCODE_DOWN;
    extern const uint32_t key_left = SDL_SCANCODE_LEFT;
    extern const uint32_t key_right = SDL_SCANCODE_RIGHT;
    extern const uint32_t key_escape = SDL_SCANCODE_ESCAPE;
    extern const uint32_t key_rocket = SDL_SCANCODE_V;


    void neu::InputSystem::Initialize() {
        const uint8_t* keyboardState = SDL_GetKeyboardState(&m_numKeys);

        m_keyboardState.resize(m_numKeys);
        std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());

        m_prevKeyboardState = m_keyboardState;
    }

    void neu::InputSystem::Shutdown() {
        //
    }


    void neu::InputSystem::Update() {

        SDL_Event event;
        SDL_PollEvent(&event);

        //Save previous keyboard state
        m_prevKeyboardState = m_keyboardState;

        //Get current keyboard state
        const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
        std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());

        m_prevMouseButtonState = m_mouseButtonState;
        int x, y;
        uint32_t buttons = SDL_GetMouseState(&x, &y);
        m_mousePosition = neu::Vector2(x, y);
        //std::cout << m_mousePosition.x << " , " << m_mousePosition.y << std::endl;
        m_mouseButtonState[0] = buttons & SDL_BUTTON_LMASK;
        m_mouseButtonState[1] = buttons & SDL_BUTTON_MMASK;
        m_mouseButtonState[2] = buttons & SDL_BUTTON_RMASK;

        //for (auto state : m_keyboardState) {
            //std::cout << (bool)state << std::endl;
        //}
    }


    InputSystem::KeyState InputSystem::GetKeyState(uint32_t key) {
        KeyState state = KeyState::Idle;

        bool keyDown = GetKeyDown(key);
        bool prevKeyDown = GetPreviousKeyDown(key);

        if (keyDown && prevKeyDown) { state = KeyState::Held; }
        else if (keyDown && !prevKeyDown) { state = KeyState::Press; }
        else if (!keyDown && prevKeyDown) { state = KeyState::Press; }
        else { state = KeyState::Idle; }

        return state;
    }

    InputSystem::KeyState InputSystem::GetButtonState(uint32_t button) {

        KeyState state = KeyState::Idle;

        bool buttonDown = GetButtonDown(button);
        bool prevButtonDown = GetPreviousButtonDown(button);

        if (buttonDown && prevButtonDown) { state = KeyState::Held; }
        else if (buttonDown && !prevButtonDown) { state = KeyState::Press; }
        else if (!buttonDown && prevButtonDown) { state = KeyState::Press; }
        else { state = KeyState::Idle; }

        return state;

    }
}