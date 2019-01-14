defmodule Nof do
  @on_load :init

  def init(), do: :ok = :erlang.load_nif("./nof_nif", 0)

  def nof() do
    exit(:nif_library_not_loaded)
  end
end
