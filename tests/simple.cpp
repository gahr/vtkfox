#include "vtkFXRenderWindowInteractor.h"
#include "FXVTKCanvas.h"

#include <vtkRenderer.h>
#include <vtkRenderWindow.h>

#define HAVE_GL_H
#include <fx3d.h>
#include <memory>


class Window : public FXMainWindow
{
		FXDECLARE(Window)
		
	public:
		Window(FXApp *app)
				: FXMainWindow(app, "vtkFOX Simple Test", NULL, NULL, DECOR_ALL, 50, 50, 640, 480)
				, vis(new FXGLVisual(app, VISUAL_DOUBLEBUFFER))
		{
			FXHorizontalFrame *frame = new FXHorizontalFrame(this, LAYOUT_FILL_X | LAYOUT_FILL_Y);
			FXVTKCanvas *canvas = new FXVTKCanvas(frame, vis.get(), NULL, 0, LAYOUT_FILL_X | LAYOUT_FILL_Y);
			
			//
			// do vtk stuff
			//
			
			vtkRenderer *ren = vtkRenderer::New();
			ren->SetBackground(0.5, 0.5, 0.5);
			
			vtkRenderWindow *renWindow = vtkRenderWindow::New();
			renWindow->AddRenderer(ren);
			
			canvas->getInteractor()->SetRenderWindow(renWindow);
			canvas->getInteractor()->Initialize();
		}
		
	protected:
		Window()
		{}
		
	private:
		std::auto_ptr<FXGLVisual> vis;
};


FXIMPLEMENT(Window, FXMainWindow, NULL, 0)


int main( int argc, char *argv[] )
{
	FXApp app("simple", "vtkFOX");
	app.init(argc, argv);
	
	Window *win = new Window(&app);
	
	app.create();
	win->show(PLACEMENT_SCREEN);
	
	return app.run();
}
