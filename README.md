# BattleTank
Open World Head-to-Head Tank Fight, Simple AI, Terrain, Advance Control System, Simple UI in Unreal 4

# List
* BT01 Documents, Notes, Git Preparation
* BT02 Set up GitHub "Repo"
* BT03 Organize Directory, Create Unreal Project
* BT04 Configure Default Scene, Ready for Terrain
* BT05 Terrain Sculpt
* BT06 Terrain Material, Terrain Texture Paint, Flat Shading group to Normal
* BT07 Import Tank Parts Meshes, Create BP for Tank (Prefab), Parent SM in BP, Create Sockets for correct position, Re-organize Meshes file structures
* BT08 Create BattleTankGameMode BP, Set Default Pawn as Tank_BP, Adjust Player Start position for spawning
* BT09 Create Camera & Spring Arm component in Tank_BP, 
    Input Binding of Camera Amizuth & Elevation (Mouse & Gamepad),
    Setup Input Event Graph in Tank_BP, Bind by AddLocalRotation to SpringArm
* BT10 Add Scene Component to separate Camera Amizuth & Elevation, Uncheck Spring Arm Inheret Roll to remain horizontal level in inclined terrains
* BT11 Create PlayerUI Widget, Add AimPoint, Create TankPlayerController BP, connect Player UI
* BT12 New Level for Main Menu, Create MainMenuUI Widget, Level BP connects MainMenu UI, Menu Background Image 
* BT13 Activate Cursor at start, Add Title & Button in Main Menu
* BT14 Start Button (OnClick) to main game, 
    Initialize start for UI only input mode for different Controls,
    Quit Key (works similar to Start)
* BT15 Change Input Mode to Game Only after start game (MainMenuUI BP)
* BT16 Create Tank class for Tank BP (Pawn) referencing, Create TankPlayerController class for TankPlayerController BP referencing
* BT17 BeginPlay() override from Actor class in TankPlayerController class,
    Check if Pawn (Tank) is possessed & Log Out result 
* BT18 Create TankAIController class, Check if Pawns (Tank) are possessed & Log Out result 
* BT19 AI Controller finds Player Tank, Pointer Protections 
* BT20 Player Controller add Tick, ready for Aim towards crosshair (Player Targeting) 
* BT21 Create RayTrace method in PlayerController to return whether Hit lanscape, HitLocation will be out parameter 
