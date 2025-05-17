return {
  'whonore/Coqtail',
  opts = {},
  init = function()
    vim.cmd([[
      augroup CoqtailHighlight
      autocmd!
      autocmd ColorScheme * hi def CoqtailChecked   guibg=#4E5E27
                        \ | hi def CoqtailSent      guibg=#546A1D
      augroup END
    ]])
  end,
  config = function()
    local prefix = "\\c"
    vim.g.coqtail_map_prefix = prefix

-- \cc to start

    vim.keymap.set("n", prefix .. "n", ":CoqNext<CR>", {desc = "Coq next"})
    vim.keymap.set("n", prefix .. "e", ":CoqUndo<CR>", {desc = "Coq undo"})
  end
}
