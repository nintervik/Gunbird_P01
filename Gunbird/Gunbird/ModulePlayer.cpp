#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "Animation.h"
#include "ModuleAudio.h"
#include "SDL\include\SDL_timer.h"

#include "ModuleEnemies.h"

//TODO: include the maps
#include "ModuleSceneCastle.h"

ModulePlayer::ModulePlayer()
{
	// idle animation
	idle.PushBack({ 0, 0, 31, 30 });
	idle.PushBack({ 38, 0, 31, 29 });
	idle.speed = 0.05f;

	//TODO: the animations are wrong

	//idle right animation
	left_idle_animation.PushBack({ 114, 38, 21, 29 });
	left_idle_animation.PushBack({ 145, 76, 21, 29 });
	left_idle_animation.loop = true;
	left_idle_animation.speed = 0.1f;

	//idle left animation

	//dead animation
	dead_animation.PushBack({ 76, 0, 32, 38 });
	dead_animation.speed = 0.1f; // TODO: is it necessary if animation is only one frame long?

	//dead animation EXPLOSION
	dead_animation_explosion.PushBack({ 95,187,47,49});
	dead_animation_explosion.PushBack({ 72,151,35, 37});
	dead_animation_explosion.PushBack({ 88,114,31,31});
	dead_animation_explosion.speed = 0.2f;

	//right animation
	right_animation.PushBack({ 0, 38, 26, 30 });
	right_animation.PushBack({ 38, 38, 26, 29 });
	right_animation.PushBack({ 76, 38, 21, 30 });
	right_animation.PushBack({ 114, 38, 21, 29 });
	right_animation.speed = 0.2f;
	right_animation.loop = false;

	//left animation
	left_animation.PushBack({ 0, 74, 28, 33 });
	left_animation.PushBack({ 36, 74, 28, 33 });
	left_animation.PushBack({ 74, 74, 25, 33 });
	left_animation.PushBack({ 112, 74, 25, 33 });
	left_animation.speed = 0.2f;
	left_animation.loop = false;

	//Blink animation
	blink.PushBack({ 0,0,31,30 });
	blink.PushBack({ 28,431,31,30 });
	blink.PushBack({ 38, 0, 31, 29 });
	blink.speed = 0.5f;
	blink.loop = true;

	//Player collison animation
	{
		playerCollision_Anim.PushBack({ 1178, 614, 26, 30 });
		playerCollision_Anim.PushBack({ 1221, 614, 31, 30 });
		playerCollision_Anim.PushBack({ 1266, 614, 26, 29 });
		playerCollision_Anim.PushBack({ 1308, 614, 25, 30 });
		playerCollision_Anim.PushBack({ 1352, 612, 31, 32 });
		playerCollision_Anim.PushBack({ 1404, 612, 31, 32 });
		playerCollision_Anim.PushBack({ 1448, 613, 29, 30 });
		playerCollision_Anim.PushBack({ 1492, 613, 31, 32 });
		playerCollision_Anim.PushBack({ 1536, 613, 29, 30 });
		playerCollision_Anim.PushBack({ 1580, 613, 31, 31 });
		playerCollision_Anim.PushBack({ 1627, 613, 31, 32 });
		playerCollision_Anim.PushBack({ 1177, 662, 31, 32 });
		playerCollision_Anim.PushBack({ 1218, 662, 31, 32 });
		playerCollision_Anim.PushBack({ 1262, 662, 31, 32 });
		playerCollision_Anim.PushBack({ 1311, 662, 31, 32 });
		playerCollision_Anim.PushBack({ 1358, 662, 31, 32 });
		playerCollision_Anim.PushBack({ 1405, 662, 31, 32 });
		playerCollision_Anim.PushBack({ 1447, 662, 31, 32 });
		playerCollision_Anim.PushBack({ 1495, 662, 31, 32 });
		playerCollision_Anim.PushBack({ 1538, 662, 31, 32 });
		playerCollision_Anim.PushBack({ 1583, 662, 31, 32 });
		playerCollision_Anim.PushBack({ 1624, 662, 31, 32 });
		playerCollision_Anim.PushBack({ 1176, 758, 31, 32 });
		playerCollision_Anim.PushBack({ 1217, 758, 31, 32 });
		playerCollision_Anim.PushBack({ 1265, 758, 31, 32 });
		playerCollision_Anim.PushBack({ 1310, 758, 31, 32 });
		playerCollision_Anim.PushBack({ 1355, 758, 31, 32 });
		playerCollision_Anim.PushBack({ 1402, 758, 31, 32 });
		playerCollision_Anim.PushBack({ 1449, 758, 31, 32 });
		playerCollision_Anim.PushBack({ 1496, 758, 31, 32 });
		playerCollision_Anim.PushBack({ 1541, 758, 31, 32 });
		playerCollision_Anim.PushBack({ 1588, 758, 31, 32 });
		playerCollision_Anim.PushBack({ 1631, 758, 31, 32 });
		playerCollision_Anim.PushBack({ 1178, 811, 31, 32 });
		playerCollision_Anim.PushBack({ 1213, 811, 31, 32 });
		playerCollision_Anim.PushBack({ 1261, 811, 31, 32 });
		playerCollision_Anim.PushBack({ 1309, 811, 31, 32 });
		playerCollision_Anim.PushBack({ 1356, 811, 31, 32 });
		playerCollision_Anim.PushBack({ 1399, 811, 31, 32 });
		playerCollision_Anim.PushBack({ 1447, 811, 31, 32 });
		playerCollision_Anim.PushBack({ 1497, 811, 31, 32 });
		playerCollision_Anim.PushBack({ 1543, 811, 31, 32 });
		playerCollision_Anim.PushBack({ 1584, 811, 31, 32 });
		playerCollision_Anim.PushBack({ 1629, 811, 31, 32 });
		playerCollision_Anim.PushBack({ 1178, 859, 31, 32 });
		playerCollision_Anim.PushBack({ 1214, 859, 31, 32 });
		playerCollision_Anim.PushBack({ 1259, 859, 31, 32 });
		playerCollision_Anim.PushBack({ 1309, 859, 31, 32 });
		playerCollision_Anim.PushBack({ 1353, 859, 31, 32 });
		playerCollision_Anim.PushBack({ 1399, 859, 31, 32 });
		playerCollision_Anim.speed = 0.5f;
		playerCollision_Anim.loop = true;
	}
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	hitted = false;
	shotPower = 0;
	spawnTime = 0;
	godModeControl = false;
	playerExpControl = false;
	playerLives = 2;
	playerLost = false;
	deadPlayer = false;
	original_camera_y = App->render->camera.y;
	laserType = 0;

	position.x = SCREEN_WIDTH / 2;
	position.y = SCREEN_HEIGHT / 2 + 100;

	LOG("Creating player collider");
	playerCollider = App->collision->AddCollider({ position.x,position.y,31,30 }, COLLIDER_PLAYER, this);
	
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Assets/characters/valnus_spritesheet.png");
	if (graphics == nullptr)
		ret = false;

	LOG("Loading player audios");
	valnus_Hitted = App->audio->LoadFx("Assets/audio/effects/Valnus_hit_enemy.wav");
	valnus_PowerUp = App->audio->LoadFx("Assets/audio/effects/Valnus_voice_PowerUp.wav");
	valnus_Death = App->audio->LoadFx("Assets/audio/effects/Valnus_Scream_hitted.wav");

	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	update_status status = UPDATE_CONTINUE;

	int speed = 3;
	

	if (!deadPlayer && !hitted) {
		if ((App->sceneCastle->background_y == -SCREEN_HEIGHT && App->sceneCastle->IsEnabled())) 
		{
			speed = 5;
			position.y -= speed;
		}
		else {

			if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				if (position.x < SCREEN_WIDTH - 34) // TODO: correct limits so they are all equal
					position.x += speed;
				if (current_animation != &right_animation)
				{
					current_animation = &right_animation;
					right_animation.Reset();
				}
			}

			if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) {
				if (position.x > 3)
					position.x -= speed;
				if (current_animation != &left_animation)
				{
					left_animation.Reset();
					current_animation = &left_animation;
				}
			}

			if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
			{
				if (position.y > 34)
					position.y -= speed;
			}

			if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
			{
				if (position.y <  SCREEN_HEIGHT - 3)
					position.y += speed;
			}

			if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || (0 < counter))
			{
				//Old switch. Keep it it here for now
				/*switch (laserType)
				{
				case 0:
					App->particles->AddParticle(App->particles->laser0, position.x + 9, position.y - 40, COLLIDER_PLAYER_SHOT);
					break;
				case 1:
					App->particles->AddParticle(App->particles->laser1, position.x + 8, position.y - 40, COLLIDER_PLAYER_SHOT);
					break;
				case 2:
					App->particles->AddParticle(App->particles->laser2, position.x + 10, position.y - 40, COLLIDER_PLAYER_SHOT);
					break;
				default:
					break;
				}
				laserType++;
				if (laserType > 2)
					laserType = 0;*/
				if (shotPower == 0) {
					if (counter == 0)
					{
						App->particles->AddParticle(App->particles->laser0, position.x + 8, position.y - 40, COLLIDER_PLAYER_SHOT);
						shotControl = false;
					}
					else if (counter == 7)
					{
						App->particles->AddParticle(App->particles->laser1, position.x + 8, position.y - 40, COLLIDER_PLAYER_SHOT);
					}
					else if (counter == 14)
					{
						App->particles->AddParticle(App->particles->laser2, position.x + 8, position.y - 40, COLLIDER_PLAYER_SHOT);
					}
					else if (counter == 21)
					{
						App->particles->AddParticle(App->particles->laser0, position.x + 8, position.y - 40, COLLIDER_PLAYER_SHOT);
						counter = 0;
						shotControl = true;
					}

					if (!shotControl)
						counter++;
				}
				else if (shotPower == 1) {
					if (counter == 0)
					{
						App->particles->AddParticle(App->particles->laser0_1, position.x + 3, position.y - 38, COLLIDER_PLAYER_SHOT);
						shotControl = false;
					}
					else if (counter == 7)
					{
						App->particles->AddParticle(App->particles->laser1_1, position.x + 3, position.y - 38, COLLIDER_PLAYER_SHOT);
					}
					else if (counter == 14)
					{
						App->particles->AddParticle(App->particles->laser2_1, position.x + 3, position.y - 38, COLLIDER_PLAYER_SHOT);
					}
					else if (counter == 21)
					{
						App->particles->AddParticle(App->particles->laser0_1, position.x + 3, position.y - 38, COLLIDER_PLAYER_SHOT);
						counter = 0;
						shotControl = true;
					}

					if (!shotControl)
						counter++;
				}
				
			} //end shot space

			if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN && App->sceneCastle->IsEnabled())
			{
				godModeControl = !godModeControl;
				inmortal = !inmortal;
			}

			if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_DOWN && App->sceneCastle->IsEnabled())
			{
				playerLives = 0;
				deadPlayer = true;
				playerExpControl = true;
			}
			
			if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
				current_animation = &idle;

		}
		App->render->camera.y = original_camera_y;
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	//update player collider
	playerCollider->SetPos(position.x, position.y - r.h);

	if (!App->render->Blit(graphics, position.x, position.y -r.h, &r)) {
		LOG("Cannot blit the texture in ModulePlayer %s\n", SDL_GetError());
		status = UPDATE_ERROR;
	}

	if (App->sceneCastle->background_y >= -2090 && App->sceneCastle->background_y < -2015)
	{
		if(App->sceneCastle->background_y == -2090)
		{ 
		this->position.x = (SCREEN_WIDTH / 2) - 13;
		this->position.y = SCREEN_HEIGHT + 24;
		}
		current_animation = &blink;
		position.y -= 1;
	}

	if (this->deadPlayer) {

		current_animation = &dead_animation;
		
		if (!inmortal) {
			App->particles->AddParticle(App->particles->deathPlayerExplosion, (playerCollider->rect.x - ((60 - ((playerCollider->rect.w)) / 2))), (playerCollider->rect.y - ((110 - (playerCollider->rect.h)) / 2)));
			inmortal = true;
		}
		
		if(lastTime == 0)
			lastTime = SDL_GetTicks();

		if (currentTime < lastTime + 2000)
		{
			position.y += speed;
		}
		else {
			if (playerLives < 0) {
				playerLost = true;
			}
			else {
				if (spawnTime == 0) {
					spawnTime = SDL_GetTicks();
					playerLives--;
					this->position.x = (SCREEN_WIDTH / 2) - 13;
					this->position.y = SCREEN_HEIGHT + 24;
				}

				//change this animation to blink
				current_animation = &blink;
			
				if (currentTime < spawnTime + 1000)
				{
					position.y -= 1;
				}
				else {
					spawnTime = 0;
					this->deadPlayer = false;
					lastTime = SDL_GetTicks();
				}
			}
		}
	}

	if (hitted) {
		current_animation = &playerCollision_Anim;
		hitted = false;
	}

	//inmortal control time
	if (currentTime > (lastTime + INMORTAL_TIME) && inmortal && (godModeControl == false) && spawnTime == 0) {
		App->player->inmortal = false;
		lastTime = 0;
	}

	//hitted control time
	if (currentTime > (hittedTime + HITTED_TIME) && hitted) {
		hitted = false;
	}

	currentTime = SDL_GetTicks();

	return status;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	LOG("Unloading player sound fx");
	App->audio->UnLoadFx(valnus_Hitted);
	App->audio->UnLoadFx(valnus_Death);
	App->audio->UnLoadFx(valnus_PowerUp);

	return true;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2) {
	if (c2->type == COLLIDER_POWER_UP)
	{
		shotPower = 1;
		App->audio->PlayFx(valnus_PowerUp);
	}
	if (!inmortal && spawnTime == 0) {

		if (c2->type == COLLIDER_TYPE::COLLIDER_ENEMY_SHOT && !hitted) {
			this->removePowerUp();
			App->audio->PlayFx(valnus_Hitted);
		}

		if (c2->type == COLLIDER_TYPE::COLLIDER_ENEMY_FLYING && !hitted) {
			this->removePowerUp();
			hitted = true;
			App->audio->PlayFx(valnus_Hitted);
		}

		if (c2->type == COLLIDER_ENEMY_SHOT)
		{
			this->deadPlayer = true;
		}
			
		if (deadPlayer == true) {
			App->particles->AddParticle(App->particles->deathPlayerExplosion, (c1->rect.x - ((130 - (c1->rect.w)) / 2)), (c1->rect.y - ((130 - (c1->rect.h)) / 2)));
			App->audio->PlayFx(valnus_Death);
		}
	}
}

void ModulePlayer::removePowerUp() {
	if (!hitted) {
		hittedTime = SDL_GetTicks();
		hitted = true;
		if (shotPower > 0) {
			shotPower = 0;
			App->enemies->AddEnemy(ENEMY_TYPES::POWER_UP, position.x, position.y - 50, ENEMY_MOVEMENT::NO_MOVEMENT);
		}
	}
}