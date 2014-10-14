class RecieveController < ApplicationController
  def index
  end

  def number
  end

  def take
    if params["number"].to_i==1
      @success = true
    elsif params["number"].to_i==2
      @success = false
    else
      redirect_to pay_handle_path
    end
  end
end
