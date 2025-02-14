#pragma once

#ifndef GUI_hpp
#define GUI_hpp

#include "CEGUI/CEGUI.h"
#include "CEGUI/RendererModules/OpenGL/GL3Renderer.h"

#include "../estados/estados.h"
#include <SkyEngine/InputManager.h>

struct vec4f{
	float x, y, z, w;
};

class GUI {
public:
    GUI(){ eventManager = InputManager::Instance(); actualState = states::Instance(); }
    virtual void init(CEGUI::RenderTarget* target);
    void destroy();
    void draw();
    virtual ~GUI();
    
    virtual void update();
    virtual void render();
	
	void beginRender() { m_renderer->beginRendering(); }
	void endRender() { m_renderer->endRendering(); }
	
    void loadScheme(const std::string& schemeFile);
    void setFont(const std::string& fontFile);
    
    CEGUI::Window* createWidget(const std::string& type, const vec4f& destRectPerc, const vec4f& destRectPix, const std::string& name="");
    
    CEGUI::Window* loadLayout(const std::string& layout);
    
    void showMouseCursor(bool show);
    void setMouseCursor(const std::string& mouse);
    
//    CEGUI::Key::Scan irrlichtToCeguiKey(irr::EKEY_CODE key);
    
//    void injectKeyDown(irr::EKEY_CODE key);
//    
//    void injectKeyUp(irr::EKEY_CODE key);
	
    void injectMousePosition(dvector2D pos);
    
    void injectLeftMouseButton() {
        m_context->injectMouseButtonDown(CEGUI::MouseButton::LeftButton);
    }
    
    void injectLeftMouseButtonUp() {
        m_context->injectMouseButtonUp(CEGUI::MouseButton::LeftButton);
    }
    
    void injectRightMouseButton() {
        m_context->injectMouseButtonDown(CEGUI::MouseButton::RightButton);
    }
    
    void injectMouseClick() {
        m_context->injectMouseButtonClick(CEGUI::MouseButton::LeftButton);
    }
    
    static void setWidgetDestRect(CEGUI::Window* widget, const vec4f& destRectPerc, const vec4f& destRectPix);
    //Getters
    CEGUI::OpenGL3Renderer* getRenderer() { return m_renderer; }
    //CEGUI::IrrlichtRenderer* getIrrlichtRenderer() { return m_rendererIrrlicht; }
    const CEGUI::GUIContext* getContext() { return m_context; }
    
    bool debugInput = false;
    
    
protected:
    bool activo;
    states* actualState;
    InputManager* eventManager;
	CEGUI::OpenGL3Renderer* m_renderer;
//	CEGUI::IrrlichtRenderer* m_rendererIrrlicht;
private:
	
    CEGUI::GUIContext* m_context = nullptr;
    
    CEGUI::Window* m_root = nullptr;
    
    unsigned int m_lastTime = 0;
};

#endif

