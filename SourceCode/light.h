#pragma once

class light
{
public:
	light();
	~light();

	void init();
	void update();
	void render() const;

protected:
	bool isHit();

private:
	VECTOR2 transform_;
	VECTOR2 velocity_;
};

