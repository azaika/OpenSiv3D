﻿# include <Siv3D.hpp>
# include <HamFramework.hpp>

void Main()
{
	ScalableWindow::SetBaseSize(640, 480);
	Window::Resize(1280, 720);
	Graphics::SetBackground(Palette::Darkgreen);

	const PlayingCard::Pack pack(75, Palette::Red);
	Array<PlayingCard::Card> cards = PlayingCard::CreateDeck(2);
	Camera2D camera;

	const Texture texture(L"example/windmill.png");

	TextBox textbox(Font(40), 40, 40, 200);

	while (System::Update())
	{
		auto tc = camera.createTransformer();
		auto ts = ScalableWindow::CreateTransformer();
		camera.update();
		textbox.update();
		texture.draw();

		for(auto i : step(5))
		{
			const Vec2 pos(320 + i * 20, 240);
			Transformer2D t2(Mat3x2::Rotate(i*5_deg, pos));
			pack(PlayingCard::Card(PlayingCard::Heart, i+1)).drawAt(pos);
		}

		textbox.draw();

		camera.draw();
		ScalableWindow::DrawBlackBars();
	}
}