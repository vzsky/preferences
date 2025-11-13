local servers = {
  lua_ls = {},
  clangd = {}, -- add CPLUS_INCLUDE to .zshrc solves header seeking 
  eslint = {},
  -- hls = {},
  ts_ls = {},
  texlab = {},
  pyright = {},
  marksman = {},
  -- ocamllsp = {},
}

return {
  'neovim/nvim-lspconfig',
  dependencies = {
    'hrsh7th/cmp-nvim-lsp',
    'williamboman/mason.nvim',
    'williamboman/mason-lspconfig.nvim',
    { 'j-hui/fidget.nvim', tag = "legacy", opts = {} },
    'folke/neodev.nvim',
  },
  config = function()
    require("neodev").setup({})
    require("mason").setup()

    require("mason-lspconfig").setup({
      ensure_installed = vim.tbl_keys(servers)
    })

    local capabilities = vim.lsp.protocol.make_client_capabilities()
    capabilities = require('cmp_nvim_lsp').default_capabilities(capabilities)

    for server_name, settings in pairs(servers) do
      vim.lsp.config(server_name, settings)
    end

    local telescope_list = function(options)
      require("telescope.builtin").loclist({
        results = options.items,
        prompt_title = "LSP Definitions",
      })
    end

    vim.keymap.set('n', '<leader>e', vim.diagnostic.open_float, {desc="show code Error"})
    vim.keymap.set('n', '<leader>h', vim.lsp.buf.hover, {desc="Hover"})
    vim.keymap.set('n', '<leader>d', vim.lsp.buf.definition, {desc="goto Definition"})
    vim.keymap.set('n', '<leader>t', vim.lsp.buf.type_definition, {desc="show Type"})
    vim.keymap.set('n', '<leader>ca', vim.lsp.buf.code_action, {desc="Code Action"})

    vim.keymap.set("n", "<leader>gr", function()
      vim.lsp.buf.references() -- context, {on_list = telescope_list}
    end, { desc = "Goto References" })

    vim.keymap.set('n', '<leader>gi', function ()
      vim.lsp.buf.implementation() -- {on_list = telescope_list}
    end, {desc="Goto Implementation"})

  end
}
