//
//  menuManager.cpp
//  estados
//
//  Created by Stoycho Ivanov Atanasov on 15/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "menuManager.hpp"

#include "../components/ventana.hpp"

menuManager::menuManager(){
	menus.insert(std::pair<tipoMenu,GUI*>(tmMENUPRINCIPAL, new MenuPrincipalLayout()));
    menus.insert(std::pair<tipoMenu, GUI*>(tmOPCIONES, new OpcionesLayout()));
    menus.insert(std::pair<tipoMenu, GUI*>(tmCREDITOS, new CreditosLayout()));
	menus.insert(std::pair<tipoMenu,GUI*>(tmPAUSE, new PausaLayout()));
	menus.insert(std::pair<tipoMenu,GUI*>(tmELEGIR_PERSONAJE, new ElegirPersonaje()));
	
	seleccionado = menus.at(tmMENUPRINCIPAL);
	actualState = states::Instance();
	m_IrrlichtRenderer = nullptr;
}

menuManager::~menuManager(){
	std::map<tipoMenu,GUI*>::iterator it = menus.begin();
	while (it != menus.end()) {
		delete it->second;
		++it;
	}
	menus.clear();
}

void menuManager::update(const long &timePerFrame){
//	printf("Menu: %d\n",seleccionado->getID());

	seleccionado = menus.at(actualState->menu);
}

void menuManager::render(float &interpolation){
    seleccionado->update();
    glDisable(GL_DEPTH_TEST);
	m_IrrlichtRenderer->beginRendering();
	seleccionado->render();
	m_IrrlichtRenderer->endRendering();
    glEnable(GL_DEPTH_TEST);
}

void menuManager::InitRenderer(){
    if (m_IrrlichtRenderer == nullptr) {
//        m_IrrlichtRenderer = &CEGUI::IrrlichtRenderer::bootstrapSystem(*ventana::Instance()->getDevice());
		const dvector2D *v = ventana::Instance()->getSize();
		CEGUI::Sizef tam(v->x,v->y);
		m_IrrlichtRenderer = &CEGUI::OpenGL3Renderer::bootstrapSystem(tam);
        const std::string resourcesPath("3d/GUI");
        
        CEGUI::DefaultResourceProvider* resourceProvider = static_cast<CEGUI::DefaultResourceProvider*>(CEGUI::System::getSingleton().getResourceProvider());
        
        resourceProvider->setResourceGroupDirectory("imagesets", resourcesPath + "/imagesets/");
        resourceProvider->setResourceGroupDirectory("schemes", resourcesPath + "/schemes/");
        resourceProvider->setResourceGroupDirectory("fonts", resourcesPath + "/fonts/");
        resourceProvider->setResourceGroupDirectory("layouts", resourcesPath + "/layouts/");
        resourceProvider->setResourceGroupDirectory("looknfeels", resourcesPath + "/looknfeel/");
        resourceProvider->setResourceGroupDirectory("lua_scripts", resourcesPath + "/lua_scripts/");
        
        CEGUI::ImageManager::setImagesetDefaultResourceGroup("imagesets");
        CEGUI::Scheme::setDefaultResourceGroup("schemes");
        CEGUI::Font::setDefaultResourceGroup("fonts");
        CEGUI::WidgetLookManager::setDefaultResourceGroup("looknfeels");
        CEGUI::WindowManager::setDefaultResourceGroup("layouts");
        CEGUI::ScriptModule::setDefaultResourceGroup("lua_scripts");
        m_target = &m_IrrlichtRenderer->getDefaultRenderTarget();
		states::Instance()->renderTarget = m_target;
		states::Instance()->renderer = m_IrrlichtRenderer;
    }
}

void menuManager::Init() {
    InitRenderer();
    
    std::map<tipoMenu,GUI*>::iterator iter = menus.begin();
    while(iter != menus.end()) {
        iter->second->init(m_target);
        
        ++iter;
    }
    hud.init();
}

