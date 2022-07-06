# Adjust window with
if app.ENABLE_FOV_OPTION:
	FOV_WINDOW_Y = 440 + 25 # window y begin

	window["height"] = window["height"] + 15 + 10
	window["children"][0]["height"] = window["children"][0]["height"] + 15 + 10
	window["children"][0]["children"] = window["children"][0]["children"] + [
		{
			"name" : "fov_window",
			"type" : "window",

			"x" : 0,
			"y" : FOV_WINDOW_Y,

			"width" : 305,
			"height" : 22 + 20,

			"children" :
			[
				{
					"name" : "fov_option",
					"type" : "text",

					"x" : 30,
					"y" : 2,

					"text" : uiScriptLocale.FOV_OPTION,
				},
				{
					"name" : "fov_controller",
					"type" : "sliderbar",

					"x" : 110,
					"y" : 5,
				},
				{
					"name" : "fov_reset_button",
					"type" : "button",

					"x" : 30 + 205,
					"y" : 1,

					"tooltip_text" : uiScriptLocale.FOV_RESET_OPTION_TOOLTIP,

					"default_image" : "d:/ymir work/ui/game/windows/reset_badge_button_default.tga",
					"over_image" : "d:/ymir work/ui/game/windows/reset_badge_button_over.tga",
					"down_image" : "d:/ymir work/ui/game/windows/reset_badge_button_down.tga",
				},
				{
					"name" : "fov_value_text",
					"type" : "text",

					"x" : 30 + 230,
					"y" : 3,

					"text" : "0",
				},
			],
		},
	]
