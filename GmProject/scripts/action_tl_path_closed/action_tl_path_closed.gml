/// action_tl_path_closed(enable)
/// @arg enable

function action_tl_path_closed(enable)
{
	if (history_undo)
	{
		with (history_data)
		{
			for (var t = 0; t < save_var_amount; t++)
			{
				with (save_id_find(save_var_save_id[t]))
				{
					path_closed = other.save_var_old_value[t]
					path_update = true
				}
			}
		}
	}
	else if (history_redo)
	{
		with (history_data)
		{
			for (var t = 0; t < save_var_amount; t++)
			{
				with (save_id_find(save_var_save_id[t]))
				{
					path_closed = other.save_var_new_value[t]
					path_update = true
				}
			}
		}
	}
	else
	{
		var hobj = history_save_var_start(action_tl_path_closed, false);
		
		with (obj_timeline)
			if (selected)
				action_tl_path_closed_tree(id, enable, hobj)
	}
}
