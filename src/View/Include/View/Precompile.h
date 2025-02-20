#pragma once

#include <thread>
#include <utility>
#include <atomic>

#include <boost/signals2.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>

#include <QWidget>
#include <QObject>
#include <QLabel>
#include <Qt>
#include <QEvent>
#include <QKeyEvent>
#include <QBackingStore>
#include <iostream>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>
#include <QPainter>
#include <QResizeEvent>
