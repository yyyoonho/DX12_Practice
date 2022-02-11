#pragma once

class Scene;

class SceneManager
{
	DECLARE_SINGLE(SceneManager);

public:
	void Update();
	void LoadScene(wstring sceneName);
	void Render();

public:
	shared_ptr<Scene> GetActiveScene() { return _activeScene; }

private:
	shared_ptr<Scene> LoadTestScene();

private:
	shared_ptr<Scene> _activeScene;
	
};

