from PyQt4 import QtGui, QtCore, QtOpenGL
from base_viewer import BaseViewer
from libpytoolkit import Display
from libpytoolkit import RendererBase
from libpytoolkit import Vec3F
from .libs import Vec3

from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *


class Dot(BaseViewer):
    
    def __init__(self, main, parent=None):
#         super(Sphere, self).__init__(main, parent)
        BaseViewer.__init__(self, main, parent)
        self.title = "Dot"
        
        self.renderer = Display()
        self.s = RendererBase()
#         self.color = QtGui.QColorDialog().getColor()
        self.color = QtGui.QColor(120, 0, 0, 150)
        
        self.main = main
        
        self.loc = Vec3(0., 0., 0.)
        
        self.selectEnabled    = True
        self.mouseMoveEnabled = True
        
    def draw(self):
        self.setMaterials(self.color)
        self.s.drawSphere(self.loc, 1.)
        
    def selectionMove(self, v):
        print "     In: selectionMove", self
        self.loc += v
        self.draw()
        
    def getCOM(self):
        return self.loc