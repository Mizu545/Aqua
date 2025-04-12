import bpy 
import array 

class Aqua(bpy.types.RenderEngine):
    bl_idname = "AQUA" 
    bl_label = "Aqua" 
    bl_use_preview = True

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.scene_data = None
        self.draw_data = None
    def __del__(self):
        super().__del__()
    def render(self, depsgraph):
        scene = depsgraph.scene
        scale = scene.render.resolution_percentage / 100.0
        self.size_x = int(scene.render.resolution_x * scale)
        self.size_y = int(scene.render.resolution_y * scale)
    if self.is_preview:
        color = [0.1, 0.2, 0.1, 1.0]
    else:
        color = [0.2, 0.1, 0.1, 1.0]
