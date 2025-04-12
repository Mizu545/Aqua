import bpy 
import array 

class Aqua(bpy.types.RenderEngine):
    bl_idname = "Aqua" 
    bl_label = "Custom" 
    bl_use_preview = True

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.scene_data = None
        self.draw_data = None

