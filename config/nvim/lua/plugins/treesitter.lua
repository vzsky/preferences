return {
  'nvim-treesitter/nvim-treesitter',
  config = function ()
    require('nvim-treesitter.configs').setup {
      ensure_installed = {"lua", "python", "cpp", "latex", "typescript"},
      highlight = {
        enable = true;
      },
      indent = {
        enable = true;
      }
    }
  end
}
