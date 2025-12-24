return {
  'nvim-lualine/lualine.nvim',
  dependencies={
    "vzsky/gitlab-codeowners.nvim",
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
        function ()
          local co = require("gitlab-codeowners").short_codeowners() -- or codeowners()
          if not co then return "" else return co end
        end,
        'filetype',
      },
      lualine_y = {'progress'},
      lualine_z = {'location'}
    },
  },
}

