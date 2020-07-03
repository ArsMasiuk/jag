# This file is a part of JAG
#
# (c) 2010-2020 Alexander Korchenko
# (c) 2010-2020 Ars L. Masiuk (ars.masiuk@gmail.com)
#
# It can be used freely, maintaining the information above.


TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += jag
jag.file = $$PWD/jag.pro

SUBDIRS += editor
editor.file = $$PWD/editor/editor.pro
