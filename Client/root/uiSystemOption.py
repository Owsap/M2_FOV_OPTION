''' 1. '''
# Search @ def __Initialize
		self.ctrlShadowQuality = 0

# Add below
		if app.ENABLE_FOV_OPTION:
			self.fovController = None
			self.fovResetButton = None
			self.fovValueText = None

''' 3. '''
# Search
			self.ctrlShadowQuality = GetObject("shadow_bar")

# Add below
			if app.ENABLE_FOV_OPTION:
				self.fovController = GetObject("fov_controller")
				self.fovController.SetButtonVisual("d:/ymir work/ui/game/windows/",\
					"sliderbar_cursor_button.tga",\
					"sliderbar_cursor_button.tga",\
					"sliderbar_cursor_button.tga")
				self.fovController.SetBackgroundVisual("d:/ymir work/ui/game/windows/sliderbar_small.tga")
				self.fovResetButton = GetObject("fov_reset_button")
				self.fovValueText = GetObject("fov_value_text")

''' 4. '''
# Search
		self.ctrlShadowQuality.SetSliderPos(float(systemSetting.GetShadowLevel()) / 5.0)
		self.ctrlShadowQuality.SetEvent(ui.__mem_func__(self.OnChangeShadowQuality))

# Add below
		if app.ENABLE_FOV_OPTION:
			if self.fovController:
				self.fovController.SetSliderPos(float(systemSetting.GetFOV()) / float(app.MAX_CAMERA_PERSPECTIVE))
				self.fovController.SetEvent(ui.__mem_func__(self.__OnChangeFOV))

			if self.fovValueText:
				self.fovValueText.SetText(str(int(systemSetting.GetFOV())))

			if self.fovResetButton:
				self.fovResetButton.SetEvent(ui.__mem_func__(self.__OnClickFOVResetButton))

''' 5. '''
# Search
	def OnChangeMusicVolume(self):

# Add below
	if app.ENABLE_FOV_OPTION:
		def __OnChangeFOV(self):
			pos = self.fovController.GetSliderPos()
			systemSetting.SetFOV(pos * float(app.MAX_CAMERA_PERSPECTIVE))

			if self.fovValueText:
				self.fovValueText.SetText(str(int(systemSetting.GetFOV())))

		def __OnClickFOVResetButton(self):
			self.fovController.SetSliderPos(float(app.DEFAULT_CAMERA_PERSPECTIVE) / float(app.MAX_CAMERA_PERSPECTIVE))
			systemSetting.SetFOV(float(app.DEFAULT_CAMERA_PERSPECTIVE))

			if self.fovValueText:
				self.fovValueText.SetText(str(int(systemSetting.GetFOV())))
