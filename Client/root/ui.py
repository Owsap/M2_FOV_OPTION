''' 1. '''
# Search @ class SliderBar
	def Disable(self):
		self.cursor.Hide()

# Add below
	if app.ENABLE_FOV_OPTION:
		def SetBackgroundVisual(self, filename):
			if self.backGroundImage:
				self.backGroundImage.LoadImage(filename)

				self.SetSize(self.backGroundImage.GetWidth(), self.backGroundImage.GetHeight())
				self.pageSize = self.backGroundImage.GetWidth() - self.cursor.GetWidth()

			if self.cursor:
				self.cursor.SetRestrictMovementArea(0, 0, self.backGroundImage.GetWidth(), 0)

		def SetButtonVisual(self, path, up, over, down):
			if self.cursor:
				self.cursor.SetUpVisual(path + up)
				self.cursor.SetOverVisual(path + over)
				self.cursor.SetDownVisual(path + down)
