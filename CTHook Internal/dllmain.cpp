#include "dllmain.h"

bool StageEnd = false;

static EventListener* eventListener = nullptr;

DWORD WINAPI Stage1(LPVOID hInstance)
{
	return 0x1337; // ok u found some antipasta
	
	pGlowManager = *(CGlowObjectManager **)(FindPattern("client_panorama.dll", "\x0F\x11\x05\x00\x00\x00\x00\x83\xC8\x01\xC7\x05\x00\x00\x00\x00\x00\x00\x00\x00", "xxx????xxxxx????xxxx") + 3);
	//pViewRender = **reinterpret_cast<CViewRender***>(FindPattern("client.dll", "\xFF\x50\x14\xE8\x00\x00\x00\x00\x5D", "xxxx????x") - 7);
	//MsgFunc_ServerRankRevealAll = reinterpret_cast<MsgFunc_ServerRankRevealAllFn>(FindPattern("client.dll", "\x55\x8B\xEC\x8B\x0D\x00\x00\x00\x00\x68", "xxxxx????x"));
	//IsReadyCallback = reinterpret_cast < IsReady > ((DWORD)FindPattern("client.dll", "\x55\x8B\xEC\x83\xE4\xF8\x83\xEC\x08\x56\x8B\x35\x00\x00\x00\x00\x57\x83\xBE", "xxxxxxxxxxxx????xxx"));
	KeyValues_KeyValues = FindPattern("client_panorama.dll", "\x68\x00\x00\x00\x00\x8B\xC8\xE8\x00\x00\x00\x00\x89\x45\xFC\xEB\x07\xC7\x45\x00\x00\x00\x00\x00\x8B\x03\x56", "x????xxx????xxxxxxx?????xxx"); KeyValues_KeyValues += 7; KeyValues_KeyValues = KeyValues_KeyValues + *reinterpret_cast< PDWORD_PTR >(KeyValues_KeyValues + 1) + 5;
	KeyValues_LoadFromBuffer = FindPattern("client_panorama.dll", "\xE8\x00\x00\x00\x00\x80\x7D\xF8\x00\x00\x00\x85\xDB", "x????xxxx??xx"); KeyValues_LoadFromBuffer = KeyValues_LoadFromBuffer + *reinterpret_cast< PDWORD_PTR >(KeyValues_LoadFromBuffer + 1) + 5;
	pPredSeed = *(int**)(FindPattern("client_panorama.dll", "\x8B\x0D\x00\x00\x00\x00\xBA\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x04", "xx????x????x????xxx") + 2);
	dwPresent = (DWORD_PTR**)(FindPattern("gameoverlayrenderer.dll", "\xA3\x00\x00\x00\x00\x68\x00\x00\x00\x00\xFF\x76\x54\xE8\x00\x00\x00\x00\x83\xC4\x08\x84\xC0\x75\x17", "x????x????xxxx????xxxxxxx") + 1);
	pClientState = *(CClientState**)(FindPattern("engine.dll", "\x8B\x3D\x00\x00\x00\x00\x8A\xF9", "xx????xx") + 2); pClientState = *(CClientState**)(pClientState);
	pGameRules = *(CSGameRulesProxy***)(FindPattern("client_panorama.dll", "\xA1\x00\x00\x00\x00\x85\xC0\x0F\x84\x00\x00\x00\x00\x80\xB8\x00\x00\x00\x00\x00\x0F\x84\x00\x00\x00\x00\x0F\x10\x05", "x????xxxx????xx?????xx????xxx") + 0x1);
	csPlayerResource = *(C_CSPlayerResource***)(FindPattern("client_panorama.dll", "\xA1\x00\x00\x00\x00\x57\x85\xC0\x74\x08", "x????xxxxx") + 1);
	pD3device = **reinterpret_cast<IDirect3DDevice9***>(FindPattern("shaderapidx9.dll", "\xA1\x00\x00\x00\x00\x50\x8B\x08\xFF\x51\x0C", "x????xxxxxx") + 1);
	pMoveHelper = **(IMoveHelper***)(FindPattern("client_panorama.dll", "\x8B\x0D\x00\x00\x00\x00\x8B\x45\x00\x51\x8B\xD4\x89\x02\x8B\x01", "xx????xx?xxxxxxx") + 2);

	pGameMovement = (IGameMovement*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("client_panorama.dll"), "CreateInterface"))	("GameMovement001", nullptr));
	pPrediction = (IPrediction*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("client_panorama.dll"), "CreateInterface"))	("VClientPrediction001", nullptr));
	pInputSystem = (IInputSystem*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("inputsystem.dll"), "CreateInterface"))	("InputSystemVersion001", nullptr));
	pSurface = (ISurface*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("vguimatsurface.dll"), "CreateInterface"))		("VGUI_Surface031", nullptr));
	pPanel = (IVPanel*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("vgui2.dll"), "CreateInterface"))		("VGUI_Panel009", nullptr));
	pPhysics = (IPhysicsSurfaceProps*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("vphysics.dll"), "CreateInterface"))	("VPhysicsSurfaceProps001", nullptr));
	pMaterial = (IMaterialSystem*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("materialsystem.dll"), "CreateInterface"))		("VMaterialSystem080", nullptr));
	pCvar = (ICvar*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("materialsystem.dll"), "CreateInterface"))		("VEngineCvar007", nullptr));
	pGameui = (CGameUI*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("client_panorama.dll"), "CreateInterface"))		("GameUI011", nullptr));
	pClient = (IBaseClientDLL*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("client_panorama.dll"), "CreateInterface"))		("VClient018", nullptr));
	pEntityList = (IClientEntityList*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("client_panorama.dll"), "CreateInterface"))		("VClientEntityList003", nullptr));
	pTrace = (IEngineTrace*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("engine.dll"), "CreateInterface"))		("EngineTraceClient004", nullptr));
	pModelInfo = (IVModelInfo*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("engine.dll"), "CreateInterface"))		("VModelInfoClient004", nullptr));
	pModelRender = (IVModelRender*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("engine.dll"), "CreateInterface"))		("VEngineModel016", nullptr));
	pEngine = (IEngineClient*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("engine.dll"), "CreateInterface"))		("VEngineClient014", nullptr));
	pDebugOverlay = (IVDebugOverlay*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("engine.dll"), "CreateInterface"))		("VDebugOverlay004", nullptr));
	pGameEvent = (IGameEventManager2*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("engine.dll"), "CreateInterface"))		("GAMEEVENTSMANAGER002", nullptr));
	pLocalize = (ILocalize*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("localize.dll"), "CreateInterface"))		("Localize_001", nullptr));
	pEffects = (CEffects*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("engine.dll"), "CreateInterface"))		("VEngineEffects001", nullptr));
	pSound = (IEngineSound*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("engine.dll"), "CreateInterface"))		("IEngineSoundClient003", nullptr));
	pInputInternal = (IInputInternal*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("vgui2.dll"), "CreateInterface"))		("VGUI_InputInternal", nullptr)); 

	pRenderView = (IVRenderView*)(CreateInterfaceFn(GetProcAddress(GetModuleHandleA("engine.dll"), "CreateInterface"))		("VEngineRenderView014", nullptr));
	pViewRenderBeams = (IViewRenderBeams*)(FindPattern("client_panorama.dll", "\x8D\x43\xFC\xB9\x00\x00\x00\x00\x50\xA1", "xxxx????xx") + 4);

	pClientMode = **(IClientMode***)((*(DWORD**)pClient)[10] + 0x5);
	pGlobalVars = **(CGlobalVars***)((*(DWORD**)pClient)[0] + 0x1B);
	//pInput = *(CInput**)((*(DWORD**)pClient)[15] + 0x1);
	pInput = *(CInput**)(FindPattern("client_panorama.dll", "\xB9\x00\x00\x00\x00\xF3\x0F\x11\x04\x24\xFF\x50\x10", "x????xxxxxxxx") + 1);

	NetVarManager::DumpNetvars();
	Offsets::GetOffsets();

	//Settings::LoadSettings();

	esp_font = pSurface->CreateFontA();
	pSurface->SetFontGlyphSet(esp_font, "Smallest Pixel-7", 12, 50, 0, 0, (int)FontFlags::FONTFLAG_OUTLINE);

	esp_name_font = pSurface->CreateFontA();
	pSurface->SetFontGlyphSet(esp_name_font, "Verdana Bold", 12, 50, 0, 0, (int)FontFlags::FONTFLAG_DROPSHADOW);
	weapon_icon = pSurface->CreateFontA();
	pSurface->SetFontGlyphSet(weapon_icon, "Counter-Strike", 22, 500, 0, 0, (int)FontFlags::FONTFLAG_ANTIALIAS);

	weapon_icon_custom = pSurface->CreateFontA();
	pSurface->SetFontGlyphSet(weapon_icon_custom, "csgoicons", 20, 500, 0, 0, (int)FontFlags::FONTFLAG_ANTIALIAS);

	lby_font = pSurface->CreateFontA();
	pSurface->SetFontGlyphSet(lby_font, "Verdana Bold", 30, 800, 0, 0, (int)FontFlags::FONTFLAG_ANTIALIAS | (int)FontFlags::FONTFLAG_DROPSHADOW);

	freestanding_font = pSurface->CreateFontA();
	pSurface->SetFontGlyphSet(freestanding_font, "Arial Black", 30, 800, 0, 0, (int)FontFlags::FONTFLAG_OUTLINE);

	pEngine->ClientCmd_Unrestricted("clear");
	pCvar->ConsoleColorPrintf(Color(255, 255, 255), "\n\n\n\nCTHOOK\n\n\n\nInjected");

	/*icon_font = pSurface->CreateFontA();
	pSurface->SetFontGlyphSet(icon_font, "badcache", 20, 800, 0, 0, (int)FontFlags::FONTFLAG_OUTLINE);
	title_font = pSurface->CreateFontA();
	pSurface->SetFontGlyphSet(title_font, "BEBAS", 20, 800, 0, 0, (int)FontFlags::FONTFLAG_OUTLINE);*/

	renderer.Initialize(FindWindowA("Valve001", NULL), pD3device);

	D3D9Hook = std::make_unique<VMTHook>(pD3device);
	D3D9Hook->HookFunction(Hooks::hReset, 16);
	D3D9Hook->HookFunction(Hooks::hkEndScene, 42);

	dwAddress = *dwPresent;
	//Present = (Present_t)(*dwAddress);
	//*dwAddress = (DWORD_PTR)(Hooks::hPresent);

	SceneEndHook = std::make_unique<VMTHook>(pRenderView);
	SceneEndHook->HookFunction(Hooks::SceneEnd, 9);

	pInputInternalHook = std::make_unique<VMTHook>(pInput);
	pInputInternalHook->HookFunction(Hooks::SetKeyCodeState, 92);
	pInputInternalHook->HookFunction(Hooks::SetMouseCodeState, 93);

	PanelHook = std::make_unique<VMTHook>(pPanel);
	PanelHook->HookFunction(Hooks::hPaintTraverse, 41);

	SurfaceHook = std::make_unique<VMTHook>(pSurface);
	SurfaceHook->HookFunction(Hooks::hPlaySounds, 82);
	SurfaceHook->HookFunction(Hooks::hLockCursor, 67);

	MaterialHook = std::make_unique<VMTHook>(pMaterial);
	MaterialHook->HookFunction(Hooks::hBeginFrame, 42);

	SoundHook = std::make_unique<VMTHook>(pSound);
	//SoundHook->HookFunction(Hooks::hEmitSound1, 5);
	//SoundHook->HookFunction(Hooks::hEmitSound2, 6);

	ModelRenderHook = std::make_unique<VMTHook>(pModelRender);
	ModelRenderHook->HookFunction(Hooks::hDrawModelExecute, 21);

	ClientModeHook = std::make_unique<VMTHook>(pClientMode);
	ClientModeHook->HookFunction(Hooks::hCreateMove, 24);
	ClientModeHook->HookFunction(Hooks::hOverrideView, 18);
	ClientModeHook->HookFunction(Hooks::hGetViewModelFOV, 35);

	ClientHook = std::make_unique<VMTHook>(pClient);
	ClientHook->HookFunction(Hooks::hFrameStageNotify, 37); // 36

	//FireEventHook = std::make_unique<VMTHook>((DWORD**)pGameEvent);
	//FireEventHook->HookFunction(Hooks::hFireEventClientSide, 9);

	eventListener = new EventListener({
		"cs_game_disconnected", "player_connect_full", "player_death",
		"player_hurt", "switch_team", "item_purchase", "bomb_beginplant",
		"bomb_begindefuse", "bomb_planted", "enter_bombzone", "player_given_c4",
		"hostage_follows", "hostage_rescued", "weapon_fire", "round_start", "bullet_impact"
		});

	//RenderViewHook = std::make_unique<VMTHook>(pViewRender);
	//RenderViewHook->HookFunction(Hooks::hRenderView, 6); crashing

	//OpenConsole();
	//std::cout << fabs(clock() - Timer) / CLOCKS_PER_SEC;

	ExitThread(0);
}

DWORD WINAPI Stage2(LPVOID hInstance)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(10000));
	while (pInputSystem && !pInputSystem->IsButtonDown(KEY_END))
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	//if (Open)
	//	FreeConsole();

	//std::this_thread::sleep_for(std::chrono::milliseconds(100));
	//*dwAddress = (DWORD_PTR)Present;

	//std::this_thread::sleep_for(std::chrono::milliseconds(100));
	//RenderViewHook->UnhookFunction(6);

	//std::this_thread::sleep_for(std::chrono::milliseconds(100));
	//SoundHook->UnhookFunction(5);

	//std::this_thread::sleep_for(std::chrono::milliseconds(100));
	//SoundHook->UnhookFunction(6);

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	SurfaceHook->UnhookFunction(82);

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	D3D9Hook->UnhookFunction(16);

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	D3D9Hook->UnhookFunction(42);

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	PanelHook->UnhookFunction(41);

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	ModelRenderHook->UnhookFunction(21);

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	ClientModeHook->UnhookFunction(18);

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	ClientModeHook->UnhookFunction(24);

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	ClientModeHook->UnhookFunction(35);

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	ClientHook->UnhookFunction(36);

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	FireEventHook->UnhookFunction(9);

	FreeLibraryAndExitThread(HINSTANCE(hInstance), 0);
}


BOOL WINAPI CreateThreads(HINSTANCE hInstance)
{
	return CreateThread(nullptr, 0, Stage1, hInstance, 0, nullptr) && CreateThread(nullptr, 0, Stage2, hInstance, 0, nullptr);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	Timer = clock();
	if (fdwReason == 1 && FindWindow("Valve001", 0)) {
		return CreateThreads(hinstDLL);
	}
}
