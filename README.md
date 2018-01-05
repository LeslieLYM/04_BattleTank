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
* BT22 Find Crosshair Position in pixel coordinate in GetSideRayHitLocation (RayTrace method)
* BT23 Deproject Screen Position of Crosshair to World Direction (Unit Vector), Refractor the part to new method
* BT24 Line Trace by Channel to return the Hit Location in the world. (Can use GetHitResultAtScreenPosition())
* BT25 Unify Aiming of player & AI by adding AimAt() in Pawn, Create AimAtComponent in Pawn through C++ so Pawn AimAt calls the Componenet to perform AimAt funciton
* BT26 GetBarrelReference Location (shoot begin location), BlueprintCallable in Tank.cpp (Pawn), Function in Aiming Component 
* BT27 Add Launch Speech in Tank.cpp (Pawn) & ready for SuggestProjectileVelocity()
* BT28 SuggestProjectileVelocity(), Return AimDirection for launching bullets
* BT29 Create MoveBarrel() in TankAimingComponent, Get Current Barrel Rotation, AimDirection, DeltaRotation
* BT30 Create custom Static Mesh Component class TankBarrel, 
    Forward Declaration in TankAimingComponent.h, 
    Make TankBarrel Blueprint Spawnable, 
    Create private variables for moving Barrel
* BT31 (L141, L142) (v4.16.3) Forward Declarations for all classes, Bug fixed for SuggestProjectileVelocity()
* BT32 (L143) (v4.16.3) Elevate Barrel with clamped values
* BT33 (L144, L145) (v4.16.3) Create custom Static Mesh Component class TankTurrent, 
    Forward Declaration in TankAimingComponent.h, 
    Make TankTurrent Blueprint Spawnable, 
    Rotate Turrent
* BT34 (L146) (v4.16.3) Create Fire() in Tank.cpp (Pawn), Create Projectile class & BP
* BT35 (L150, L151) (v4.16.3) Spawn Actor Projectile BP in scene, Launch Projectiles with SetVelocityInLocalSpace() with Launch Speed
* BT36 (L152) (v4.16.3) AI Tanks call Fire(), Set Reload Time for Shooting
* BT37 (L153) (v4.16.3) Change appropriate properties from EditAnywhere to EditDefaultsOnly
* BT38 (L154,L155) (v4.16.3) Add Quit Button in Main Menu Widget, Create custom Static Mesh Component class TankTrack, Make TankTrack Blueprint Spawnable, SetThrottle by Getting axis value from Input
* BT39 (L156) (v4.16.3) GetRootComponent of Tank & Cast as Primitive Component for Applying Force At Location
* BT40 (L157, L158) (v4.16.3) Fix Collision Boxes for movable tanks under appropriate speed, Create custom Nav Movement Component class TankMovementComponent ready for Fly-by-wire movements
* BT41 (L159) (v4.16.3) Forward Declaration TankMovementComponent in Tank.h, Make it BlueprintReadOnly & BlueprintCallable Function
