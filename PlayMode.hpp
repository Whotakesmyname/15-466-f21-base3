#include "Mode.hpp"

#include "Scene.hpp"
#include "Sound.hpp"

#include <glm/glm.hpp>

#include <vector>
#include <deque>

struct PlayMode : Mode {
	PlayMode();
	virtual ~PlayMode();

	//functions called by main loop:
	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;

	//----- game state -----

	//input tracking:
	struct Button {
		uint8_t downs = 0;
		uint8_t pressed = 0;
	} left, right, down, up;

	//local copy of the game scene (so code can change it during gameplay):
	Scene scene;

	// scene parameters
	glm::vec3 ambient_light = glm::vec3(.8f);
	float fog_max_vis_distance = 10.f;

	// camera parameters: yaw, pitch
	glm::vec2 cam_params = glm::vec2(0.f, glm::pi<float>()/2);
	// cache yaw quat
	glm::quat cam_yaw = glm::quat(1.f, 0.f, 0.f, 0.f);

	// transforms
	Scene::Transform *world = nullptr;

	//sound handlers
	std::shared_ptr<Sound::PlayingSample> footstep_loop;
	bool footstep_playing = false;
	std::shared_ptr<Sound::PlayingSample> blizzard_loop;
	bool blizzard_supressed = false;
	
	//camera:
	Scene::Camera *camera = nullptr;

};
