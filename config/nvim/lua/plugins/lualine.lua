return {
  'nvim-lualine/lualine.nvim',
  dependencies={
    "rsreimer/codeowners.nvim",
  },
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
      lualine_x = {
        'filetype',
        function()
          return require("codeowners").get_buf_owner();
        end,
      },
      lualine_y = {'progress'},
      lualine_z = {'location'}
    },
  },
}

