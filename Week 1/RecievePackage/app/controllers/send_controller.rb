class SendController < ApplicationController
  def index
  end

  def bill
    if params[:who_pays]==1.to_s #Odbiorca
      redirect_to send_finish_path
    else #Nadawca
      redirect_to pay_handle_path
    end
  end

  def finish
  end
end
