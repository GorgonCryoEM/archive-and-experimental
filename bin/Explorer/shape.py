from PyQt4 import QtGui, QtCore, QtOpenGL
from base_viewer import BaseViewer
from libpytoolkit import Display
from libpytoolkit import RendererBase
from .libs import Vec3

from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *


class Shape(BaseViewer):

    def __init__(self, main):
        super(Shape, self).__init__(main)
        
        self.renderer = Display()
        self.s = RendererBase()

    def setColor(self, r, g, b, a):
        self.color = QtGui.QColor(r, g, b, a)

    def setLoc(self, x, y, z):
        self.loc = Vec3(x, y, z)

    def setLocationV(self, v):
        self.setLocation(v[0], v[1], v[2])

    def setLocation(self, x, y, z):
        self.renderer.setOrigin(x, y, z)
        self.app.mainCamera.updateGL()
