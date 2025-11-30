return {
  'nvim-treesitter/nvim-treesitter',
  dependencies = {
    'nvim-treesitter/nvim-treesitter-textobjects'
  },
  build = ":TSUpdate",
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
      },
    }

    ---@diagnostic disable-next-line: missing-fields
    require('nvim-treesitter.configs').setup {
      textobjects = {
        select = {
          enable = true,
          lookahead = true,

          keymaps = {
            ["af"] = "@function.outer",
            ["if"] = "@function.inner",
            ["ai"] = "@conditional.outer",
            ["ii"] = "@conditional.inner",
          },
        },
        move = {
          enable = true,
          set_jumps = true, -- whether to set jumps in the jumplist
          goto_next_start = {
            ["<leader>na"] = "@parameter.",
            ["<leader>nf"] = "@function.inner", -- next function
            ["<leader>nl"] = "@loop.inner",
            ["<leader>ni"] = "@conditional.inner",
            ["<leader>nc"] = "@class.outer",
          },
          goto_previous_start = {
            ["<leader>Na"] = "@parameter.outd",
            ["<leader>wf"] = "@function.inner", -- which function
            ["<leader>wl"] = "@loop.inner",
            ["<leader>wi"] = "@conditional.inner",
            ["<leader>wc"] = "@class.inner",
          }
        },
      }
    }

  end
}
