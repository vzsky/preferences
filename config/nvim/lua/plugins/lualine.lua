return {
  'nvim-lualine/lualine.nvim',
  opts = {
    options = {
      theme = 'onedark',
      component_separators = '|',
      section_separators = '',
    },
    sections = {
      lualine_a = {'mode'},
      lualine_b = {{'filename', path = 1}},
      lualine_c = {'branch', 'diff', 'diagnostics'},
      lualine_x = {'filetype'},
      lualine_y = {'progress'},
      lualine_z = {'location'}
    },
  },
}
