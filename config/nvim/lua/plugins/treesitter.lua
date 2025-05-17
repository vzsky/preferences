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
            ["aa"] = "@parameter.outer",
            ["ia"] = "@parameter.inner",
            ["af"] = "@function.outer",
            ["if"] = "@function.inner",
            ["al"] = "@loop.outer",
            ["il"] = "@loop.inner",
            ["ai"] = "@conditional.outer",
            ["ii"] = "@conditional.inner",
            ["a="] = "@assignment.outer",
            ["=l"] = "@assignment.lhs",
            ["=r"] = "@assignment.rhs",
            ["ac"] = "@class.outer",
            ["ic"] = "@class.inner",
          },
        },
        move = {
          enable = true,
          set_jumps = true, -- whether to set jumps in the jumplist
          goto_next_start = {
            ["ma"] = "@parameter.inner",
            ["mf"] = "@function.inner",
            ["ml"] = "@loop.inner",
            ["mi"] = "@conditional.inner",
            ["m="] = "@assignment.inner",
            ["mc"] = "@class.inner",
          },
          goto_previous_start = {
            ["Ma"] = "@parameter.inner",
            ["Mf"] = "@function.inner",
            ["Ml"] = "@loop.inner",
            ["Mi"] = "@conditional.inner",
            ["M="] = "@assignment.inner",
            ["Mc"] = "@class.inner",
          }
        },
      }
    }

    local ts_repeat_move = require "nvim-treesitter.textobjects.repeatable_move"

    vim.keymap.set({ "n", "x", "o" }, ";", ts_repeat_move.repeat_last_move_next, {desc="move to next TS mark"})
    vim.keymap.set({ "n", "x", "o" }, "<leader>;", ts_repeat_move.repeat_last_move_previous, {desc="move to previous TS mark"})
  end
}
