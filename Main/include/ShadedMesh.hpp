#pragma once

class ShadedMesh {
public:
	ShadedMesh(const String& name);
	ShadedMesh(const String& name, const String& path);
	ShadedMesh();
    virtual ~ShadedMesh() = default; // Virtual so we can dynamiccast

	void Draw();
	void SetData(Vector<MeshGenerators::SimpleVertex>& data);
	void AddTexture(const String& name, const String& file);
	void AddSkinTexture(const String& name, const String& file);
    int AddSharedTexture(const String& name, const String& key);
	void SetBlendMode(const MaterialBlendMode& mode);
	void SetPrimitiveType(const PrimitiveType& type);
	void SetOpaque(bool opaque);

	template<typename T>
	void SetParam(const String& name, const T& value) {
		m_params.SetParameter(name, value);
	}

	static int lNew(struct lua_State* L);

	static Map<String, void*> FunctionMap;

protected:
	Mesh m_mesh;
	Material m_material;
	MaterialParameterSet m_params;
	Map<String, Texture> m_textures;
};

class ShadedMeshOnTrack : public ShadedMesh {
public:
	ShadedMeshOnTrack(class Game* game, const String& name) : ShadedMesh(name), m_game(game) { }
	ShadedMeshOnTrack(class Game* game, const String& name, const String& path) : ShadedMesh(name, path), m_game(game) { }
	ShadedMeshOnTrack(class Game* game) : ShadedMesh(), m_game(game) { }
	virtual ~ShadedMeshOnTrack() override = default;

	static int lNew(struct lua_State* L, class Game* game);
	void DrawOnTrack();
	void lUseGameMesh(struct lua_State* L);

	void SetTrackPos(float x, float y, float z)
	{
		m_trackPos = Vector3(x, y, z);
	}
	Vector3& GetTrackPos() { return m_trackPos; }
	void SetScale(float x, float y, float z)
	{
		m_scale = Vector3(x, y, z);
	}
	Vector3& GetScale() { return m_scale; }

	void SetLength(float l) { m_length = l; }
	float GetLength() { return m_length; }
	void SetClipping(bool c) { m_clip = c; }

	Game* GetGame() { return m_game; };

private:
	class Game* m_game = nullptr;
	Vector3 m_trackPos;
	Vector3 m_scale = Vector3(1,1,1);
	float m_length = 1;
	bool m_clip = false;
};
