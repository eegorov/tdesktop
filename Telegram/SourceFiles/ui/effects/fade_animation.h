/*
This file is part of Telegram Desktop,
the official desktop version of Telegram messaging app, see https://telegram.org

Telegram Desktop is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

It is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

In addition, as a special exception, the copyright holders give permission
to link the code of portions of this program with the OpenSSL library.

Full license: https://github.com/telegramdesktop/tdesktop/blob/master/LICENSE
Copyright (c) 2014-2016 John Preston, https://desktop.telegram.org
*/
#pragma once

class TWidget;

namespace Ui {

class FadeAnimation {
public:
	FadeAnimation(TWidget *widget);

	bool paint(Painter &p);
	void refreshCache();

	using FinishedCallback = Function<void>;
	void setFinishedCallback(FinishedCallback &&callback);

	using UpdatedCallback = Function<void, float64>;
	void setUpdatedCallback(UpdatedCallback &&callback);

	void show();
	void hide();

	void fadeIn(int duration);
	void fadeOut(int duration);

private:
	void startAnimation(int duration);
	void stopAnimation();

	void updateCallback();

	TWidget *_widget;
	FloatAnimation _animation;
	QPixmap _cache;
	bool _visible = false;

	FinishedCallback _finishedCallback;
	UpdatedCallback _updatedCallback;

};

} // namespace Ui
