/// temp_event_create()
/// @desc Create event of templates.

save_id = ""
save_id = save_id_create()
loaded = false
creator = temp_creator

type = ""
name = ""
display_name = ""
count = 0
rot_point[Z] = 0

skin = null
model_name = "human"
model_texture_name = ""
model_file = null
model_state = ""
model_state_map = null
model_part_name = ""
model_part = null

item_tex = null
item_slot = ds_list_find_index(mc_assets.item_texture_list, "items/diamond_sword")
item_vbuffer = null
item_3d = true
item_face_camera = false
item_bounce = false

block_name = "grass"
block_state = ""
block_state_map = null
block_tex = null
block_vbuffer_reset()
scenery = 0

block_repeat_enable = false
block_repeat = vec3(1)

shape_vbuffer = null
shape_tex = 0
shape_tex_mapped = false
shape_tex_hoffset = 0
shape_tex_voffset = 0
shape_tex_hrepeat = 1
shape_tex_vrepeat = 1
shape_tex_hmirror = 0
shape_tex_vmirror = 0
shape_closed = true
shape_invert = false
shape_detail = 32
shape_face_camera = false

text_font = 0
text_face_camera = false

