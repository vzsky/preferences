return {
  'nvim-treesitter/nvim-treesitter',
  config = function()
    ---@diagnostic disable-next-line: missing-fields
    require('nvim-treesitter.configs').setup {
      auto_install = true,
      ensure_installed = { "lua", "python", "cpp", "latex", "typescript" },
      highlight = {
        enable = true,
        -- disable = { "latex" },
        -- additional_vim_regex_highlighting = { "latex" },
      },
      indent = {
        enable = true,
      }
    }
  end
}
