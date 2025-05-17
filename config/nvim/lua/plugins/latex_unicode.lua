return {
  'joom/latex-unicoder.vim',
  config = function ()
    vim.g.unicoder_cancel_normal = 1
    vim.g.unicoder_cancel_insert = 1
    vim.g.unicoder_cancel_visual = 1

    vim.keymap.set("n", "<leader>lu", ":call unicoder#start(0)<CR>", {desc = "Start Latex Unicode"})
  end
}
