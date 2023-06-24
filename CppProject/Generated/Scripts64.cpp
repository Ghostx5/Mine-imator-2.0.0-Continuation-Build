/*
	NOTE:
	This file was autogenerated by CppGen, changes may be overwritten and forever lost!
	Modify at your own risk!
	
	[ Generated on 2023.06.23 22:26:54 ]
*/

#include "Scripts.hpp"

namespace CppProject
{
	void textbox_startup()
	{
		global::_app->textbox_lastfocus = -IntType(1);
		global::_app->textbox_click = false;
		global::_app->textbox_marker = IntType(0);
		global::_app->textbox_mouseover = -IntType(1);
		global::_app->textbox_select_startline = IntType(0);
		global::_app->textbox_select_startpos = IntType(0);
		global::_app->textbox_select_endline = IntType(0);
		global::_app->textbox_select_endpos = IntType(0);
		global::_app->textbox_select_mouseline = IntType(0);
		global::_app->textbox_select_mousepos = IntType(0);
		global::_app->textbox_select_clickline = IntType(0);
		global::_app->textbox_select_clickpos = IntType(0);
		global::_app->textbox_isediting = false;
		global::_app->textbox_isediting_respond = false;
		global::_app->textbox_input = /*""*/ STR(0);
		global::_app->textbox_jump = false;
		global::_app->textbox_jumpto = -IntType(1);
		global::_app->textbox_list = ds_list_create();
	}
	
	void textfield_group_add(ScopeAny self, VarArgs argument)
	{
		IntType argument_count = argument.Size();
		sVar(textfield_name) = array_add(VarType::CreateRef(sVar(textfield_name)), argument[IntType(0)]);
		sVar(textfield_value) = array_add(VarType::CreateRef(sVar(textfield_value)), argument[IntType(1)]);
		sVar(textfield_default) = array_add(VarType::CreateRef(sVar(textfield_default)), argument[IntType(2)]);
		sVar(textfield_script) = array_add(VarType::CreateRef(sVar(textfield_script)), argument[IntType(3)]);
		sVar(textfield_axis) = array_add(VarType::CreateRef(sVar(textfield_axis)), argument[IntType(4)]);
		sVar(textfield_textbox) = array_add(VarType::CreateRef(sVar(textfield_textbox)), argument[IntType(5)]);
		if (sBool(textbox_jump))
			ds_list_add({ sInt(textbox_list), ArrType::From({ argument[IntType(5)], sVar(content_tab), sVar(dy), sVar(content_y), sVar(content_height) }) });
		if (argument_count > IntType(6))
			sVar(textfield_icon) = array_add(VarType::CreateRef(sVar(textfield_icon)), argument[IntType(6)]);
		else
			sVar(textfield_icon) = array_add(VarType::CreateRef(sVar(textfield_icon)), null_);
		
		if (argument_count > IntType(7))
			sVar(textfield_mul) = array_add(VarType::CreateRef(sVar(textfield_mul)), argument[IntType(7)]);
		else
			sVar(textfield_mul) = array_add(VarType::CreateRef(sVar(textfield_mul)), null_);
		
		if (argument_count > IntType(8))
		{
			sVar(textfield_min) = array_add(VarType::CreateRef(sVar(textfield_min)), argument[IntType(8)]);
			sVar(textfield_max) = array_add(VarType::CreateRef(sVar(textfield_max)), argument[IntType(9)]);
		}
		if (argument_count > IntType(10))
			sVar(textfield_caption) = array_add(VarType::CreateRef(sVar(textfield_caption)), argument[IntType(10)]);
		else
			sVar(textfield_caption) = array_add(VarType::CreateRef(sVar(textfield_caption)), null_);
		
		sReal(textfield_amount) = array_length(VarType::CreateRef(sVar(textfield_name)));
	}
	
	void textfield_group_reset(ScopeAny self)
	{
		sVar(textfield_name) = null_;
		sVar(textfield_value) = null_;
		sVar(textfield_default) = null_;
		sVar(textfield_script) = null_;
		sVar(textfield_axis) = null_;
		sVar(textfield_textbox) = null_;
		sVar(textfield_icon) = null_;
		sVar(textfield_mul) = null_;
		sVar(textfield_min) = null_;
		sVar(textfield_max) = null_;
		sVar(textfield_caption) = null_;
		sReal(textfield_amount) = IntType(0);
	}
	
	IntType texture_create(VarType fn)
	{
		if (!file_exists_lib(fn))
			return texture_create_missing();
		return sprite_add_lib({ fn });
	}
	
	IntType texture_create_crop(VarType tex, RealType xx, RealType yy, RealType wid, RealType hei)
	{
		IntType ntex, surf;
		xx = -xx;
		yy = -yy;
		surf = surface_create((IntType)(wid), (IntType)(hei));
		surface_set_target(surf);
	{
		draw_clear_alpha(c_white, 0.0);
		draw_texture({ tex, xx, yy });
	}
		surface_reset_target();
		ntex = texture_surface(surf);
		surface_free(surf);
		return ntex;
	}
	
	IntType texture_create_fill(IntType color, IntType size)
	{
		IntType surf, newtex;
		surf = surface_create(size, size);
		surface_set_target(surf);
	{
		draw_clear(color);
	}
		surface_reset_target();
		newtex = texture_surface(surf);
		surface_free(surf);
		return newtex;
	}
	
	IntType texture_create_missing(IntType size)
	{
		IntType surf, newtex;
		surf = surface_create(size, size);
		surface_set_target(surf);
	{
		draw_missing(IntType(0), IntType(0), size, size);
	}
		surface_reset_target();
		newtex = texture_surface(surf);
		surface_free(surf);
		return newtex;
	}
	
	IntType texture_create_square(StringType fn)
	{
		IntType tex;
		RealType ww, hh;
		tex = texture_create(fn);
		ww = texture_width(tex);
		hh = texture_height(tex);
		if (ww == hh)
			return tex;
		RealType size;
		IntType surf, newtex;
		size = max({ ww, hh });
		surf = surface_create((IntType)(size), (IntType)(size));
		surface_set_target(surf);
	{
		draw_clear_alpha(c_black, 0.0);
		draw_texture({ tex, IntType(0), IntType(0) });
	}
		surface_reset_target();
		newtex = texture_surface(surf);
		surface_free(surf);
		texture_free(tex);
		return newtex;
	}
	
	IntType texture_duplicate(VarType tex)
	{
		return sprite_duplicate((IntType)(tex));
	}
	
	void texture_export(VarType tex, VarType fn)
	{
		sprite_save_lib(tex, IntType(0), fn);
	}
	
	void texture_free(VarType tex)
	{
		if (sprite_exists((IntType)(tex)))
			sprite_delete((IntType)(tex));
	}
	
	IntType texture_getpixel(IntType tex, VarType xx, VarType yy)
	{
		IntType surf, col;
		surf = surface_create((IntType)(texture_width(tex)), (IntType)(texture_height(tex)));
		surface_set_target(surf);
	{
		draw_texture({ tex, IntType(0), IntType(0) });
	}
		surface_reset_target();
		col = surface_getpixel(surf, (IntType)(xx), (IntType)(yy));
		surface_free(surf);
		return col;
	}
	
	RealType texture_height(VarType tex)
	{
		return sprite_get_height((IntType)(tex));
	}
	
	void texture_set_mipmap_level(VarType level)
	{
		gpu_set_tex_mip_bias((IntType)(-level));
	}
	
	ArrType texture_split(IntType tex, RealType slotsx, RealType slotsy)
	{
		RealType w, h, sw, sh;
		ArrType newtex;
		IntType surf;
		w = texture_width(tex);
		h = texture_height(tex);
		sw = max({ IntType(1), (IntType)(w / slotsx) });
		sh = max({ IntType(1), (IntType)(h / slotsy) });
		draw_texture_start();
		surf = surface_create((IntType)(sw), (IntType)(sh));
		surface_set_target(surf);
	{
		for (IntType i = IntType(0); i < slotsx * slotsy; i++)
		{
			RealType dx, dy;
			dx = (mod(i, slotsx)) * sw;
			dy = ((IntType)(i / slotsx)) * sh;
			draw_clear_alpha(c_black, 0.0);
			draw_texture_part({ tex, IntType(0), IntType(0), dx, dy, sw, sh });
			newtex[i] = texture_surface(surf);
		}
	}
		surface_reset_target();
		surface_free(surf);
		draw_texture_done();
		return newtex;
	}
	
	IntType texture_surface(IntType surf)
	{
		return sprite_create_from_surface(surf, IntType(0), IntType(0), surface_get_width(surf), surface_get_height(surf), false, false, IntType(0), IntType(0));
	}
	
	RealType texture_width(VarType tex)
	{
		return sprite_get_width((IntType)(tex));
	}
	
	IntType text_caption_width(ScopeAny self, VarArgs argument)
	{
		IntType argument_count = argument.Size();
		IntType font = draw_get_font();
		draw_set_font(sInt(font_label));
		IntType wid = IntType(0);
		for (IntType a = IntType(0); a < argument_count; a++)
			if (text_exists(argument[a]))
				wid = max({ wid, string_width(text_get({ argument[a] })) + IntType(8) });
			else
				wid = max({ wid, string_width(argument[a]) + IntType(8) });
		
		draw_set_font(font);
		return wid;
	}
	
	VarType text_control_name(VarType keybind)
	{
		VarType char_, text;
		switch ((IntType)keybind.Value(e_keybind_key_CHAR))
		{
			case vk_left:
			{
				char_ = text_get({ /*"keyleft"*/ STR(3825) });
				break;
			}
			case vk_right:
			{
				char_ = text_get({ /*"keyright"*/ STR(3826) });
				break;
			}
			case vk_up:
			{
				char_ = text_get({ /*"keyup"*/ STR(3827) });
				break;
			}
			case vk_down:
			{
				char_ = text_get({ /*"keydown"*/ STR(3828) });
				break;
			}
			case vk_enter:
			{
				char_ = text_get({ /*"keyenter"*/ STR(3829) });
				break;
			}
			case vk_escape:
			{
				char_ = text_get({ /*"keyescape"*/ STR(3830) });
				break;
			}
			case vk_space:
			{
				char_ = text_get({ /*"keyspace"*/ STR(3831) });
				break;
			}
			case vk_lshift:
			{
				char_ = text_get({ /*"keyleftshift"*/ STR(3832) });
				break;
			}
			case vk_rshift:
			{
				char_ = text_get({ /*"keyrightshift"*/ STR(3833) });
				break;
			}
			case vk_lalt:
			{
				char_ = text_get({ /*"keyleftalt"*/ STR(3834) });
				break;
			}
			case vk_ralt:
			{
				char_ = text_get({ /*"keyrightalt"*/ STR(3835) });
				break;
			}
			case vk_lcontrol:
			{
				char_ = text_get({ /*"keyleftcontrol"*/ STR(3836) });
				break;
			}
			case vk_rcontrol:
			{
				char_ = text_get({ /*"keyrightcontrol"*/ STR(3837) });
				break;
			}
			case vk_backspace:
			{
				char_ = text_get({ /*"keybackspace"*/ STR(3838) });
				break;
			}
			case vk_tab:
			{
				char_ = text_get({ /*"keytab"*/ STR(3839) });
				break;
			}
			case vk_home:
			{
				char_ = text_get({ /*"keyhome"*/ STR(3840) });
				break;
			}
			case vk_end:
			{
				char_ = text_get({ /*"keyend"*/ STR(3841) });
				break;
			}
			case vk_delete:
			{
				char_ = text_get({ /*"keydelete"*/ STR(3842) });
				break;
			}
			case vk_insert:
			{
				char_ = text_get({ /*"keyinsert"*/ STR(3843) });
				break;
			}
			case vk_pageup:
			{
				char_ = text_get({ /*"keypageup"*/ STR(3844) });
				break;
			}
			case vk_pagedown:
			{
				char_ = text_get({ /*"keypagedown"*/ STR(3845) });
				break;
			}
			case vk_pause:
			{
				char_ = text_get({ /*"keypause"*/ STR(3846) });
				break;
			}
			case vk_printscreen:
			{
				char_ = text_get({ /*"keyprintscreen"*/ STR(3847) });
				break;
			}
			case vk_f1:
			{
				char_ = /*"F1"*/ STR(3848);
				break;
			}
			case vk_f2:
			{
				char_ = /*"F2"*/ STR(3849);
				break;
			}
			case vk_f3:
			{
				char_ = /*"F3"*/ STR(3850);
				break;
			}
			case vk_f4:
			{
				char_ = /*"F4"*/ STR(3851);
				break;
			}
			case vk_f5:
			{
				char_ = /*"F5"*/ STR(3852);
				break;
			}
			case vk_f6:
			{
				char_ = /*"F6"*/ STR(3853);
				break;
			}
			case vk_f7:
			{
				char_ = /*"F7"*/ STR(3854);
				break;
			}
			case vk_f8:
			{
				char_ = /*"F8"*/ STR(3855);
				break;
			}
			case vk_f9:
			{
				char_ = /*"F9"*/ STR(3856);
				break;
			}
			case vk_f10:
			{
				char_ = /*"F10"*/ STR(3857);
				break;
			}
			case vk_f11:
			{
				char_ = /*"F11"*/ STR(3858);
				break;
			}
			case vk_f12:
			{
				char_ = /*"F12"*/ STR(3859);
				break;
			}
			case null_:
			{
				char_ = /*""*/ STR(0);
				break;
			}
			default:
				char_ = chr((IntType)(keybind.Value(e_keybind_key_CHAR)));
				break;
		}
		
		text = char_;
		if (keybind.Value(e_keybind_key_ALT) > 0)
			text = text_get({ /*"keyalt"*/ STR(3860) }) + (text != /*""*/ STR(0) ? (/*" + "*/ STR(2996) + text) : /*""*/ STR(0));
		if (keybind.Value(e_keybind_key_CTRL) > 0)
			text = text_get({ /*"keycontrol"*/ STR(3861) }) + (text != /*""*/ STR(0) ? (/*" + "*/ STR(2996) + text) : /*""*/ STR(0));
		if (keybind.Value(e_keybind_key_SHIFT) > 0)
			text = text_get({ /*"keyshift"*/ STR(3862) }) + (text != /*""*/ STR(0) ? (/*" + "*/ STR(2996) + text) : /*""*/ STR(0));
		return text;
	}
	
	RealType text_exists(VarType key)
	{
		return ds_map_exists(global::language_english_map, key);
	}
	
	VarType text_get(VarArgs argument)
	{
		IntType argument_count = argument.Size();
		VarType key;
		IntType map;
		key = argument[IntType(0)];
		map = global::language_map;
		if (!ds_map_exists(map, key))
		{
			if (!text_exists(key))
				return /*"<No text found for \""*/ STR(3863) + key + /*"\">"*/ STR(3864);
			map = global::language_english_map;
		}
		VarType text = DsMap(map).Value(key);
		for (IntType a = IntType(1); a < argument_count; a++)
			text = string_replace(text, /*"%"*/ STR(208) + string(a), argument[a]);
		return text;
	}
	
	IntType text_max_width(VarArgs argument)
	{
		IntType argument_count = argument.Size();
		IntType wid = IntType(0);
		for (IntType a = IntType(0); a < argument_count; a++)
			wid = max({ wid, string_width(text_get({ argument[a] }) + /*":"*/ STR(798)) });
		return wid;
	}
	
	RealType time_get_rotation(VarType str)
	{
		IntType colons;
		VarType days, hours, minutes;
		IntType colonpos;
		StringType daystr, hourstr, minutestr;
		colons = string_count(/*":"*/ STR(798), str);
		days = IntType(0);
		hours = IntType(0);
		minutes = IntType(0);
		if (colons > IntType(2))
			return IntType(0);
		if (colons == IntType(0))
			minutes = string_get_real(str, IntType(0));
		if (colons == IntType(1))
		{
			colonpos = string_pos(/*":"*/ STR(798), str);
			hourstr = string_copy(str, IntType(1), (IntType)(colonpos - IntType(1)));
			minutestr = string_delete(str, IntType(1), colonpos);
			hours = string_get_real(hourstr, IntType(0));
			minutes = string_get_real(minutestr, IntType(0));
		}
		if (colons == IntType(2))
		{
			colonpos = string_pos(/*":"*/ STR(798), str);
			daystr = string_copy(str, IntType(1), (IntType)(colonpos - IntType(1)));
			str = string_delete(str, IntType(1), colonpos);
			colonpos = string_pos(/*":"*/ STR(798), str);
			hourstr = string_copy(str, IntType(1), (IntType)(colonpos - IntType(1)));
			minutestr = string_delete(str, IntType(1), colonpos);
			days = string_get_real(daystr, IntType(0));
			hours = string_get_real(hourstr, IntType(0));
			minutes = string_get_real(minutestr, IntType(0));
		}
		hours -= 12.0;
		return ((days + ((RealType)(hours + ((RealType)minutes / 60.0)) / 24.0)) * IntType(360));
	}
	
	RealType tip_draw(ScopeAny self)
	{
		if (sInt(tip_window) != window_get_current())
			return IntType(0);
		if (sBool(tip_show))
			sVar(tip_alpha) = test_reduced_motion(IntType(1), min({ IntType(1), sVar(tip_alpha) + 0.1 * global::delta }));
		else
			sVar(tip_alpha) = test_reduced_motion(IntType(0), max({ IntType(0), sVar(tip_alpha) - 0.1 * global::delta }));
		
		if (sVar(tip_alpha) == IntType(0))
		{
			sVar(tip_box_x) = null_;
			sVar(tip_box_y) = null_;
			sVar(tip_final_x) = -IntType(1);
			sVar(tip_final_y) = -IntType(1);
			sVar(tip_arrow_final_x) = -IntType(1);
			sVar(tip_arrow_final_y) = -IntType(1);
			return IntType(0);
		}
		if (sVar(tip_final_x) == -IntType(1))
		{
			sVar(tip_final_x) = sVar(tip_x);
			sVar(tip_final_y) = sVar(tip_y);
			sVar(tip_arrow_final_x) = sVar(tip_arrow_x);
			sVar(tip_arrow_final_y) = sVar(tip_arrow_y);
		}
		else
		{
			sVar(tip_final_x) += (sVar(tip_x) - sVar(tip_final_x)) / max({ IntType(1), 4.0 / global::delta });
			sVar(tip_final_y) += (sVar(tip_y) - sVar(tip_final_y)) / max({ IntType(1), 4.0 / global::delta });
			sVar(tip_arrow_final_x) += (sVar(tip_arrow_x) - sVar(tip_arrow_final_x)) / max({ IntType(1), 4.0 / global::delta });
			sVar(tip_arrow_final_y) += (sVar(tip_arrow_y) - sVar(tip_arrow_final_y)) / max({ IntType(1), 4.0 / global::delta });
		}
		
		sVar(content_x) = sVar(tip_final_x);
		sVar(content_y) = sVar(tip_final_y);
		sVar(content_width) = sReal(tip_w);
		sVar(content_height) = sReal(tip_h);
		draw_set_alpha(sVar(tip_alpha));
		draw_box(sVar(tip_final_x), sVar(tip_final_y), sReal(tip_w), sReal(tip_h), false, global::c_level_top, IntType(1));
		draw_outline(sVar(tip_final_x), sVar(tip_final_y), sReal(tip_w), sReal(tip_h), IntType(1), global::c_border, global::a_border, true);
		render_set_culling(false);
		draw_image({ ID_spr_tooltip_arrow, sReal(tip_arrow) * IntType(2), sVar(tip_arrow_final_x), sVar(tip_arrow_final_y), sReal(tip_arrow_xscale), sReal(tip_arrow_yscale), global::c_level_top, IntType(1), (IntType)sBool(tip_right) * IntType(90) });
		draw_image({ ID_spr_tooltip_arrow, (sReal(tip_arrow) * IntType(2)) + IntType(1), sVar(tip_arrow_final_x), sVar(tip_arrow_final_y), sReal(tip_arrow_xscale), sReal(tip_arrow_yscale), global::c_border, global::a_border, (IntType)sBool(tip_right) * IntType(90) });
		render_set_culling(true);
		VarType texty = sVar(tip_final_y) + sReal(tip_h) - IntType(4);
		if (sBool(tip_keybind_draw))
			draw_label(self, { sVar(tip_text_keybind), sVar(tip_final_x) + sReal(tip_w) - IntType(8), texty - IntType(1), fa_right, fa_bottom, global::c_text_tertiary, global::a_text_tertiary, sInt(font_caption) });
		for (IntType i = IntType(0); i < array_length(VarType::CreateRef(sArr(tip_text_array))); i++)
		{
			StringType text = sArr(tip_text_array).Value(i);
			if (sBool(tip_keybind_draw))
				draw_label(self, { text, sVar(tip_final_x) + IntType(8), texty - IntType(1), fa_left, fa_bottom, global::c_text_main, global::a_text_main, sInt(font_caption) });
			else
				draw_label(self, { text, sVar(tip_final_x) + round(sReal(tip_w) / 2.0), texty - IntType(1), fa_center, fa_bottom, global::c_text_main, global::a_text_main, sInt(font_caption) });
			
			texty -= (8.0 + 7.0);
		}
		draw_set_alpha(1.0);
		sBool(tip_show) = false;
		return 0.0;
	}
	
	RealType tip_set(ScopeAny self, VarType text, VarType xx, VarType yy, VarType w, VarType h, BoolType checkmouse)
	{
		if (text == /*""*/ STR(0))
			return IntType(0);
		BoolType showtip;
		if (checkmouse)
			showtip = app_mouse_box(self, xx, yy, w, h) && sBool(content_mouseon);
		else
			showtip = true;
		
		if (showtip)
		{
			sInt(tip_window) = window_get_current();
			if (sVar(tip_box_x) != xx || sVar(tip_box_y) != yy || sVar(tip_text) != text)
			{
				sVar(tip_text) = text;
				if (sVar(tip_keybind) != null_)
				{
					sBool(tip_keybind_draw) = true;
					sVar(tip_text_keybind) = text_control_name(sVar(tip_keybind));
				}
				else
				{
					sBool(tip_keybind_draw) = false;
					sVar(tip_text_keybind) = /*""*/ STR(0);
				}
				
				IntType fontprev = draw_get_font();
				draw_set_font(sInt(font_caption));
				if (sBool(tip_wrap))
					sVar(tip_text_wrap) = string_wrap(sVar(tip_text), IntType(200));
				else
					sVar(tip_text_wrap) = sVar(tip_text);
				
				sArr(tip_text_array) = string_line_array(sVar(tip_text_wrap));
				sReal(tip_w) = string_width(sVar(tip_text_wrap)) + (sVar(tip_text_keybind) == /*""*/ STR(0) ? IntType(0) : string_width(sVar(tip_text_keybind)) + IntType(12));
				sReal(tip_h) = IntType(7) * (array_length(VarType::CreateRef(sArr(tip_text_array))) - IntType(1));
				sReal(tip_h) += IntType(8) * array_length(VarType::CreateRef(sArr(tip_text_array)));
				sReal(tip_w) += (IntType(8) * IntType(2));
				sReal(tip_h) += (IntType(8) * IntType(2));
				sVar(tip_x) = IntType(0);
				sVar(tip_y) = IntType(0);
				sVar(tip_x) = xx + floor(sVar(tip_x) - (sReal(tip_w) / 2.0)) + ((RealType)w / 2.0);
				sVar(tip_y) = yy + floor(sVar(tip_y)) + h + IntType(6);
				sBool(tip_right) = false;
				sReal(tip_arrow) = IntType(0);
				sReal(tip_arrow_xscale) = IntType(1);
				if (sBool(tip_force_right))
				{
					sBool(tip_right) = true;
					sVar(tip_arrow_x) = xx + w + IntType(14);
					sVar(tip_arrow_y) = yy + floor((RealType)h / 2.0);
					sReal(tip_arrow_yscale) = IntType(1);
					sVar(tip_x) = xx + w + IntType(14);
					sVar(tip_y) = yy + floor((RealType)h / 2.0 - sReal(tip_h) / 2.0);
				}
				else
				{
					sVar(tip_arrow_x) = xx + ((RealType)w / 2.0);
					sVar(tip_arrow_y) = sVar(tip_y);
					sReal(tip_arrow_yscale) = IntType(1);
					if (sVar(tip_x) < IntType(0))
					{
						sVar(tip_x) += (sReal(tip_w) / 2.0);
						sReal(tip_arrow) = IntType(1);
					}
					if (sVar(tip_x) + sReal(tip_w) > sReal(window_width))
					{
						sVar(tip_x) -= (sReal(tip_w) / 2.0);
						sReal(tip_arrow) = IntType(1);
						sReal(tip_arrow_xscale) = -IntType(1);
						sVar(tip_arrow_x) -= 1.0;
					}
					if (sVar(tip_y) + sReal(tip_h) > sReal(window_height))
					{
						sVar(tip_y) = yy - (IntType(6) + sReal(tip_h));
						sVar(tip_arrow_y) = yy - IntType(6);
						sReal(tip_arrow_yscale) = -IntType(1);
					}
					if (sReal(tip_arrow_yscale) > 0)
					{
						sVar(tip_y) += IntType(8);
						sVar(tip_arrow_y) += IntType(8);
					}
					else
					{
						sVar(tip_y) -= 8.0;
						sVar(tip_arrow_y) -= 8.0;
					}
					
				}
				
				sBool(tip_location_x) = false;
				sBool(tip_location_y) = false;
				sVar(tip_x) = floor(sVar(tip_x));
				sVar(tip_y) = floor(sVar(tip_y));
				sReal(tip_w) = floor(sReal(tip_w));
				sReal(tip_h) = floor(sReal(tip_h));
				draw_set_font(fontprev);
			}
			sBool(tip_show) = true;
			sVar(tip_box_x) = xx;
			sVar(tip_box_y) = yy;
		}
		if (sVar(tip_keybind) != null_)
			sVar(tip_keybind) = null_;
		sBool(tip_wrap) = true;
		return 0.0;
	}
	
	void tip_set_keybind(ScopeAny self, IntType argument0)
	{
		sVar(tip_keybind) = ObjType(obj_keybind, global::keybinds.Value(argument0))->keybind;
	}
	
	void tl_animate_scenery(Scope<obj_timeline> self)
	{
		if (idVar(idVar(self->temp, scenery), scenery_tl_add) == null_ || idVar(idVar(self->temp, scenery), scenery_tl_add) > 0)
		{
			self->part_list = ds_list_create();
			for (IntType i = IntType(0); i < ds_list_size(idInt(idVar(self->temp, scenery), scenery_tl_list)); i++)
				withOne (Object, DsList(idInt(idVar(self->temp, scenery), scenery_tl_list)).Value(i), self->id)
					block_animate(self, self.otherId);
			
		}
		self->scenery_animate = false;
	}
	
	void tl_copy(ScopeAny self, IntType to)
	{
		idVar(to, type) = sVar(type);
		idVar(to, name) = sVar(name);
		idVar(to, temp) = sVar(temp);
		idVar(to, text) = sVar(text);
		idVar(to, color_tag) = sVar(color_tag);
		idVar(to, lock) = sVar(lock);
		idVar(to, hide) = sVar(hide);
		idVar(to, ghost) = sVar(ghost);
		idVar(to, depth) = sVar(depth);
		idVar(to, lock_bend) = sVar(lock_bend);
		idBool(to, part_mixing_shapes) = sBool(part_mixing_shapes);
		idVar(to, parent) = sVar(parent);
		if (self->subAssetId == ID_obj_timeline)
			idVar(to, parent_tree_index) = ds_list_find_index(idInt(sVar(parent), tree_list), self->id);
		else
			idVar(to, parent_tree_index) = sVar(parent_tree_index);
		
		idVar(to, tree_extend) = sVar(tree_extend);
		idVar(to, model_part) = sVar(model_part);
		idVar(to, model_part_name) = sVar(model_part_name);
		idVar(to, part_of) = sVar(part_of);
		idVar(to, inherit_position) = sVar(inherit_position);
		idVar(to, inherit_rotation) = sVar(inherit_rotation);
		idVar(to, inherit_rot_point) = sVar(inherit_rot_point);
		idVar(to, inherit_scale) = sVar(inherit_scale);
		idVar(to, inherit_alpha) = sVar(inherit_alpha);
		idVar(to, inherit_color) = sVar(inherit_color);
		idVar(to, inherit_visibility) = sVar(inherit_visibility);
		idVar(to, inherit_bend) = sVar(inherit_bend);
		idVar(to, inherit_texture) = sVar(inherit_texture);
		idVar(to, inherit_surface) = sVar(inherit_surface);
		idVar(to, inherit_subsurface) = sVar(inherit_subsurface);
		idVar(to, inherit_glow_color) = sVar(inherit_glow_color);
		idVar(to, inherit_select) = sVar(inherit_select);
		idVar(to, inherit_pose) = sVar(inherit_pose);
		idVar(to, scale_resize) = sVar(scale_resize);
		idVar(to, rot_point_custom) = sVar(rot_point_custom);
		idVar(to, rot_point) = point3D_copy(sVar(rot_point));
		idVec(to, rot_point_render) = point3D_copy(sVec(rot_point_render));
		idVar(to, backfaces) = sVar(backfaces);
		idVar(to, texture_blur) = sVar(texture_blur);
		idVar(to, texture_filtering) = sVar(texture_filtering);
		idVar(to, shadows) = sVar(shadows);
		idVar(to, ssao) = sVar(ssao);
		idVar(to, glow) = sVar(glow);
		idVar(to, glow_texture) = sVar(glow_texture);
		idVar(to, only_render_glow) = sVar(only_render_glow);
		idVar(to, glint_mode) = sVar(glint_mode);
		idVar(to, glint_scale) = sVar(glint_scale);
		idVar(to, glint_tex) = sVar(glint_tex);
		idVar(to, fog) = sVar(fog);
		idVar(to, wind) = sVar(wind);
		idVar(to, wind_terrain) = sVar(wind_terrain);
		idVar(to, hq_hiding) = sVar(hq_hiding);
		idVar(to, lq_hiding) = sVar(lq_hiding);
		idVar(to, blend_mode) = sVar(blend_mode);
		idVar(to, alpha_mode) = sVar(alpha_mode);
		idBool(to, path_update) = true;
		idVar(to, path_smooth) = sVar(path_smooth);
		idVar(to, path_closed) = sVar(path_closed);
		idVar(to, path_detail) = sVar(path_detail);
		idVar(to, path_shape_generate) = sVar(path_shape_generate);
		idVar(to, path_shape_radius) = sVar(path_shape_radius);
		idVar(to, path_shape_tex_length) = sVar(path_shape_tex_length);
		idVar(to, path_shape_invert) = sVar(path_shape_invert);
		idVar(to, path_shape_tube) = sVar(path_shape_tube);
		idVar(to, path_shape_detail) = sVar(path_shape_detail);
		idVar(to, path_shape_smooth_segments) = sVar(path_shape_smooth_segments);
		idVar(to, path_shape_smooth_ring) = sVar(path_shape_smooth_ring);
		if (sVar(part_of) != null_ && sVar(part_of) != /*""*/ STR(0))
		{
			if (sVar(type) == e_temp_type_SPECIAL_BLOCK)
			{
				idVar(to, model_name) = sVar(model_name);
				idVar(to, model_state) = array_copy_1d(sVar(model_state));
			}
			else
				if (sVar(type) == e_temp_type_BLOCK)
				{
					idVar(to, block_name) = sVar(block_name);
					idArr(to, block_state) = array_copy_1d(sArr(block_state));
				}
			
		}
	}
	
	RealType tl_deselect(ScopeAny self)
	{
		if (!(sReal(selected) > 0))
			return IntType(0);
		sReal(selected) = false;
		if (sVar(keyframe_select) > 0)
			for (IntType k = IntType(0); k < ds_list_size(sInt(keyframe_list)); k++)
				ObjType(obj_keyframe, DsList(sInt(keyframe_list))[k])->selected = false;
		sVar(keyframe_select) = null_;
		sInt(keyframe_select_amount) = IntType(0);
		global::tl_edit_amount--;
		global::tl_edit = null_;
		withAll (obj_timeline, self->id)
			if (self->selected > 0)
				global::tl_edit = self->id;
		
		tl_update_value_types_show(Scope<obj_timeline>(self));
		tl_update_parent_is_selected(self);
		return 0.0;
	}
	
	void tl_deselect_all()
	{
		withAll (obj_timeline, noone)
		{
			if (self->selected > 0)
			{
				tl_update_value_types_show(self);
				self->selected = false;
				self->keyframe_select = null_;
				self->keyframe_select_amount = IntType(0);
			}
			self->parent_is_selected = false;
		}
		
		withAll (obj_keyframe, noone)
			self->selected = false;
		
		global::tl_edit_amount = IntType(0);
		global::tl_edit = null_;
	}
	
	IntType tl_duplicate(ScopeAny self)
	{
		sInt(copy) = (new obj_timeline)->id;
		tl_copy(self, sInt(copy));
		withOne (obj_timeline, sInt(copy), self->id)
		{
			self->root_copy = null_;
			self->copy = null_;
			self->glint_tex = idVar(self.otherId, glint_tex);
			idInt(self->glint_tex, count)++;
			tl_update_scenery_part(ScopeAny(self));
			if (self->temp != null_)
			{
				if (Obj(self->temp)->subAssetId == ID_obj_template)
				{
					if (self->part_of == null_)
						idInt(self->temp, count)++;
				}
				else
					if (self->temp == self.otherId)
						self->temp = self->id;
					else
						if (idVar(self->temp, part_of) != null_)
							self->temp = idInt(self->temp, copy);
				
				
			}
			for (IntType v = IntType(0); v < e_value_amount; v++)
				self->value_default[v] = tl_value_find_save_id(v, null_, idArr(self.otherId, value_default).Value(v));
			for (IntType k = IntType(0); k < ds_list_size(idInt(self.otherId, keyframe_list)); k++)
			{
				VarType oldkf;
				IntType newkf;
				oldkf = DsList(idInt(self.otherId, keyframe_list)).Value(k);
				newkf = (new obj_keyframe)->id;
				ObjType(obj_keyframe, newkf)->position = ObjType(obj_keyframe, oldkf)->position;
				ObjType(obj_keyframe, newkf)->timeline = self->id;
				ObjType(obj_keyframe, newkf)->selected = false;
				ObjType(obj_keyframe, newkf)->sound_play_index = null_;
				for (IntType v = IntType(0); v < e_value_amount; v++)
					ObjType(obj_keyframe, newkf)->value[v] = ObjType(obj_keyframe, oldkf)->value.Value(v);
				ds_list_add({ self->keyframe_list, newkf });
			}
			for (IntType t = IntType(0); t < ds_list_size(idInt(self.otherId, tree_list)); t++)
			{
				withOne (obj_timeline, DsList(idInt(self.otherId, tree_list)).Value(t), self->id)
					ds_list_add({ ObjType(obj_timeline, self.otherId)->tree_list, tl_duplicate(ScopeAny(self)) });
				
				ObjType(obj_timeline, DsList(self->tree_list)[t])->parent = self->id;
			}
			if (idInt(self.otherId, part_list) != null_)
			{
				self->part_list = ds_list_create();
				for (IntType p = IntType(0); p < ds_list_size(idInt(self.otherId, part_list)); p++)
				{
					IntType pcopy = idInt(DsList(idInt(self.otherId, part_list)).Value(p), copy);
					ds_list_add({ self->part_list, pcopy });
					ObjType(obj_timeline, pcopy)->part_of = self->id;
				}
			}
			if (idVar(self.otherId, pattern_type) != /*""*/ STR(0) && idVar(self.otherId, pattern_base_color) != null_)
			{
				self->pattern_type = idVar(self.otherId, pattern_type);
				self->pattern_base_color = idVar(self.otherId, pattern_base_color);
				self->pattern_pattern_list = array_copy_1d(idVar(self.otherId, pattern_pattern_list));
				self->pattern_color_list = array_copy_1d(idVar(self.otherId, pattern_color_list));
				array_add(VarType::CreateRef(global::pattern_update), self->id);
			}
			tl_update(ScopeAny(self));
			tl_update_values(ScopeAny(self));
			return self->id;
		}
		
		return IntType(0);
	}
	
	void tl_event_create(Scope<obj_timeline> self)
	{
		self->save_id = /*""*/ STR(0);
		self->save_id = save_id_create();
		self->loaded = false;
		self->type = null_;
		self->type_name = /*""*/ STR(0);
		self->name = /*""*/ STR(0);
		self->display_name = /*""*/ STR(0);
		self->temp = null_;
		self->text = text_get({ /*"timelineeditortextsample"*/ STR(3865) });
		self->color_tag = null_;
		self->lock = false;
		self->hide = false;
		self->ghost = false;
		self->delete_ready = false;
		self->depth = IntType(0);
		self->model_part = null_;
		self->model_part_name = /*""*/ STR(0);
		self->model_shape_vbuffer_map = null_;
		self->model_shape_alpha_map = null_;
		self->part_of = null_;
		self->part_list = null_;
		self->part_root = null_;
		self->scenery_animate = false;
		for (IntType v = IntType(0); v < e_value_amount; v++)
		{
			self->value_default[v] = global::_app->value_default.Value(v);
			self->value_inherit[v] = self->value_default.Value(v);
			self->value[v] = self->value_default.Value(v);
		}
		for (IntType t = IntType(0); t < e_value_type_amount; t++)
		{
			self->value_type[t] = false;
			self->value_type_show[t] = true;
		}
		self->show_tool_position = true;
		self->selected = false;
		self->keyframe_list = ds_list_create();
		self->keyframe_prev = null_;
		self->keyframe_current = null_;
		self->keyframe_next = null_;
		self->keyframe_select = null_;
		self->keyframe_select_amount = IntType(0);
		self->keyframe_progress = IntType(0);
		self->keyframe_animate = false;
		self->keyframe_current_values = null_;
		self->keyframe_next_values = null_;
		self->world_pos = point3D(IntType(0), IntType(0), IntType(0));
		self->world_pos_rotate = point3D(IntType(0), IntType(0), IntType(0));
		self->world_pos_2d = point2D(IntType(0), IntType(0));
		self->world_pos_2d_error = false;
		self->colors_ext = false;
		self->part_mixing_shapes = false;
		self->level = IntType(0);
		self->level_display = ArrType::From({});
		self->parent = null_;
		self->parent_filter = null_;
		self->parent_is_selected = false;
		self->lock_bend = true;
		self->tree_array = IntType(0);
		self->tree_list = ds_list_create();
		self->tree_list_filter = ds_list_create();
		self->tree_extend = false;
		self->tree_contents = array_create({ e_tl_type_amount - IntType(1) });
		self->list_mouseon = false;
		self->inherit_position = true;
		self->inherit_rotation = true;
		self->inherit_rot_point = false;
		self->inherit_scale = true;
		self->inherit_alpha = false;
		self->inherit_color = false;
		self->inherit_visibility = true;
		self->inherit_bend = false;
		self->inherit_texture = false;
		self->inherit_surface = true;
		self->inherit_subsurface = true;
		self->inherit_glow_color = true;
		self->inherit_select = false;
		self->inherit_pose = false;
		self->scale_resize = true;
		self->rot_point_custom = false;
		self->rot_point = point3D(IntType(0), IntType(0), IntType(0));
		self->rot_point_render = point3D(IntType(0), IntType(0), IntType(0));
		self->backfaces = false;
		self->texture_blur = false;
		self->texture_filtering = false;
		self->shadows = true;
		self->ssao = true;
		self->glow = false;
		self->glow_texture = true;
		self->only_render_glow = false;
		self->fog = true;
		self->wind = false;
		self->wind_terrain = true;
		self->hq_hiding = false;
		self->lq_hiding = false;
		self->blend_mode = /*"normal"*/ STR(643);
		self->alpha_mode = e_alpha_mode_DEFAULT;
		self->glint_mode = e_glint_NONE;
		self->glint_scale = IntType(1);
		self->glint_tex = global::mc_res;
		idInt(self->glint_tex, count)++;
		self->particle_list = null_;
		self->cam_surf_required = false;
		self->cam_surf = null_;
		self->cam_surf_tmp = null_;
		self->cam_goalzoom = null_;
		self->matrix = MAT_IDENTITY;
		self->matrix_render = MAT_IDENTITY;
		self->matrix_parent = MAT_IDENTITY;
		self->matrix_parent_pre_ik = MAT_IDENTITY;
		self->matrix_local = MAT_IDENTITY;
		self->update_matrix = true;
		self->bend_rot_last = vec3(IntType(0));
		self->bend_model_part_last = null_;
		self->pattern_type = /*""*/ STR(0);
		self->pattern_base_color = null_;
		self->pattern_pattern_list = null_;
		self->pattern_color_list = null_;
		self->pattern_skin = null_;
		self->text_vbuffer = ArrType::From({ null_, null_ });
		self->text_texture = ArrType::From({ null_, null_ });
		self->text_string = /*""*/ STR(0);
		self->text_res = null_;
		self->text_3d = false;
		self->text_halign_prev = /*"center"*/ STR(1461);
		self->text_valign_prev = /*"center"*/ STR(1461);
		self->text_aa_prev = true;
		self->item_vbuffer = null_;
		self->item_slot = IntType(0);
		self->item_res = null_;
		self->item_material_res = null_;
		self->item_normal_res = null_;
		self->item_3d = true;
		self->item_custom_slot = false;
		self->render_res_diffuse = null_;
		self->render_res_material = null_;
		self->render_res_normal = null_;
		self->tex_obj = null_;
		self->tex_obj_prev = -IntType(5);
		self->model_tex = null_;
		self->model_tex_material = null_;
		self->model_tex_normal = null_;
		self->render_visible = true;
		self->placed = false;
		self->parent_is_placed = false;
		self->path_update = false;
		self->path_points_list = ds_list_create();
		self->path_smooth = true;
		self->path_closed = false;
		self->path_detail = IntType(6);
		self->path_table = ArrType::From({});
		self->path_table_matrix = ArrType::From({});
		self->path_length = IntType(1);
		self->path_shape_generate = false;
		self->path_shape_radius = IntType(8);
		self->path_shape_tex_length = IntType(16);
		self->path_shape_invert = false;
		self->path_shape_tube = false;
		self->path_shape_detail = IntType(6);
		self->path_shape_smooth_segments = true;
		self->path_shape_smooth_ring = false;
		self->path_vbuffer = null_;
		self->path_select_vbuffer = null_;
		self->ik_target_prev = null_;
		self->ik_target_pos = ArrType::From({ IntType(0), IntType(0), IntType(0) });
		self->ik_target_angle_prev = null_;
		self->ik_target_angle_pos = ArrType::From({ IntType(0), IntType(0), IntType(0) });
		self->ik_matrix_prev = MAT_IDENTITY;
		self->ik_angle_offset_prev = IntType(0);
		self->ik_blend_prev = IntType(0);
		self->part_matrix_update_ik = false;
		self->part_joints_pos = ArrType::From({});
		self->part_joints_matrix = ArrType::From({});
		self->part_joints_bone_matrix = ArrType::From({});
		self->part_joint_bend_angle = IntType(0);
		tl_update_path(self);
	}
	
}
