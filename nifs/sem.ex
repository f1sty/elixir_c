defmodule Sem do
  @on_load :init

  def init do
    :ok = :erlang.load_nif("./sem_nif", 0)
  end

  def go do
    exit(:nif_library_not_loaded)
  end
end
