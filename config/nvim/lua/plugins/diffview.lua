return {
  "sindrets/diffview.nvim",
  config = function()
    local actions = require("diffview.actions")

    vim.keymap.set("n", "<leader>df", function ()
      vim.cmd.DiffviewOpen()
    end, { desc = "Open Diffview", })

    vim.keymap.set("n", "<leader>dc", function()
      local n = vim.fn.input("HEAD~")
      if n == "" then n = "1" end
      vim.cmd("DiffviewOpen HEAD~" .. n)
    end, { desc = "Open Diffview HEAD~n" })

    require("diffview").setup({
      keymaps = {
        disable_defaults = true,
        view = {
          { "n", "h?", actions.help("view"), { desc = "Open the help panel" } },
          { "n", "<tab>", actions.select_next_entry, { desc = "Open the diff for the next file" } },
          { "n", "<s-tab>", actions.select_prev_entry, { desc = "Open the diff for the previous file" }, },
          { "n", "<leader>f", actions.focus_files, { desc = "Bring focus to the file panel" } },
          { "n", "<leader>g", actions.toggle_files, { desc = "Toggle the file panel." } },
          { "n", "<leader>df", vim.cmd.DiffviewClose, { desc = "Close Diffview" } },
          { "n", "<leader>dc", vim.cmd.DiffviewClose, { desc = "Close Diffview" } },
          { "n", "<leader>gf", function ()
            actions.goto_file_edit()
            vim.cmd 'tabclose #'
          end, { desc = "Open the file in the previous tabpage" } },
        },

        file_panel = {
          { "n", "h?", actions.help("file_panel"), { desc = "Open the help panel" } },
          { "n", "<leader>g", actions.toggle_files, { desc = "Toggle the file panel" }, },
          { "n", "j", actions.next_entry, { desc = "Bring the cursor to the next file entry" }, },
          { "n", "k", actions.prev_entry, { desc = "Bring the cursor to the previous file entry" }, },
          { "n", "<down>", actions.next_entry, { desc = "Bring the cursor to the next file entry" }, },
          { "n", "<up>", actions.prev_entry, { desc = "Bring the cursor to the previous file entry" }, },
          { "n", "<cr>", actions.select_entry, { desc = "Open the diff for the selected entry" }, },
          { "n", "<2-LeftMouse>", actions.select_entry, { desc = "Open the diff for the selected entry" }, },
          { "n", "s", actions.toggle_stage_entry, { desc = "Stage / unstage the selected entry" }, },
          { "n", "-", actions.toggle_stage_entry, { desc = "Stage / unstage the selected entry" }, },
          { "n", "<c-b>", actions.scroll_view(-0.25), { desc = "Scroll the view up" } },
          { "n", "<c-f>", actions.scroll_view(0.25), { desc = "Scroll the view down" }, },
          { "n", "<tab>", actions.select_next_entry, { desc = "Open the diff for the next file" }, },
          { "n", "<s-tab>", actions.select_prev_entry, { desc = "Open the diff for the previous file" }, },
          { "n", "<leader>df", vim.cmd.DiffviewClose, { desc = "Close Diffview" } },
          { "n", "<leader>dc", vim.cmd.DiffviewClose, { desc = "Close Diffview" } },
          { "n", "<leader>gf", function ()
            actions.goto_file_edit()
            vim.cmd 'tabclose #'
          end, { desc = "Open the file in the previous tabpage" } },
        },

        help_panel = {
          { "n", "q", actions.close, { desc = "Close help menu" } },
          { "n", "<esc>", actions.close, { desc = "Close help menu" } },
        },
      },
    })
  end,
}
