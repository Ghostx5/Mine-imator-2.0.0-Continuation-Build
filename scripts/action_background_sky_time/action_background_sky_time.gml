/// action_background_sky_time(value, add)
/// @arg value
/// @arg add

var val, add;
add = false

if (history_undo)
	val = history_data.old_value
else if (history_redo)
	val = history_data.new_value
else
{
	val = argument0
	add = argument1
	if (action_tl_select_single("background"))
	{
		tl_value_set_start(action_background_sky_time, true)
		tl_value_set(e_value.BG_SKY_TIME, val, add)
		tl_value_set_done()
		return 0
	}
	history_set_var(action_background_sky_time, background_sky_time, background_sky_time * add + val, true)
}

background_sky_time = background_sky_time * add + val
