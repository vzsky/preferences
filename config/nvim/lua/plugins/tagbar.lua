return {
  'preservim/tagbar',
  config = function()
    vim.keymap.set("n", "<leader>tb", vim.cmd.TagbarToggle, {desc="open tagbar pane"})
  end
}
