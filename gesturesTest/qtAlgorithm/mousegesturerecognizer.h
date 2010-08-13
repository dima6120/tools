/*
 * This file is part of the mouse gesture package.
 * Copyright (C) 2006 Johan Thelin <e8johan@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the
 * following conditions are met:
 *
 *   - Redistributions of source code must retain the above
 *     copyright notice, this list of conditions and the
 *     following disclaimer.
 *   - Redistributions in binary form must reproduce the
 *     above copyright notice, this list of conditions and
 *     the following disclaimer in the documentation and/or
 *     other materials provided with the distribution.
 *   - The names of its contributors may be used to endorse
 *     or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#pragma once

#include <QString>
#include <QPoint>
#include <QList>

/*
 *  The available directions.
 */
typedef enum
{
	Right,
	Down,
	Left,
	Up,
	AnyHorizontal,
	AnyVertical,
	NoMatch
} Direction;
/*
 *  A list of directions.
 */
typedef QList<Direction> DirectionList;
typedef QList<QPoint> PosList;

/*
 *  Create lists of directions
 */
struct GestureDefinition
{
	PosList directions;
	QString object;

	GestureDefinition( const PosList &d, const QString &object )
	{
		directions = d;
		this->object = object;
	}
};

typedef QList<GestureDefinition> GestureList;

class MouseGestureRecognizer
{
public:
	MouseGestureRecognizer();
	~MouseGestureRecognizer();

	void addGestureDefinition(QString const & name, QList<QPoint> const & path);
	void clearGestureDefinitions();

	QString recognizeGesture(const QList<QPoint> & gesture);

private:
	GestureList mGestures;
	PosList filterGesture(const PosList & path);
};
