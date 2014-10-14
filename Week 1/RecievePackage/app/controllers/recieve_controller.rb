class RecieveController < ApplicationController
  def index
  end

  def number
  end

  def take
    if params["number"].to_i==1
      @success = true
    else
      @success = false
    end
  end
end
