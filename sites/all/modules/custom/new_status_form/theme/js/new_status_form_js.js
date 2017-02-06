/**
 * @file
 * JS file.
 */

(function ($) {
Drupal.behaviors.new_status = {
  attach: function (context, settings) {
    $(document).ready(function () {

      var flag = false;

      if (settings.new_status.form_height !== null) {
        var form_h = settings.new_status.form_height;
      }
      else {
        var form_h = 200;
      }

      if (settings.new_status.form_width !== null) {
        var form_w = settings.new_status.form_width;
      }
      else {
        var form_w = 500;
      }

      if (settings.new_status.form_bg !== null) {
        var form_bg = settings.new_status.form_bg;
      }
      else {
        var form_bg = 'burlywood';
      }

      $('.new-window').height(form_h);

      $('.new-window').width(form_w);

      $('.new-body').css('background-color', form_bg);

      $('.new-window').offset({top: $('.new-mask').outerHeight() / 2 - form_h / 2, left: $('.new-mask').outerWidth() / 2 - form_w / 2});

      $('.new-title-button').click(function () {
        $('.custom-template-wrapper').hide();
      });

      $('.new-mask').click(function () {
        $('.custom-template-wrapper').hide();
      });

      $('.new-window').mousedown(function(e) {

        var position = $('.new-window').position();
        var xw = getPosition(e).x - position.left;
        var yw = getPosition(e).y - position.top;		

        function getPosition(v) {
          var posx = 0;
          var posy = 0;

          if (!v) var v = window.event;

          if (v.pageX || v.pageY) {
                posx = v.pageX;
                posy = v.pageY;
          }
          else if (v.clientX || v.clientY) {
                posx = v.clientX + document.body.scrollLeft
                  + document.documentElement.scrollLeft;
                posy = v.clientY + document.body.scrollTop
                  + document.documentElement.scrollTop;
          }

          return {
                x: posx,
                y: posy
          }
        }

        function moveWindow(e) {
          var x = getPosition(e).x;
          var y = getPosition(e).y;

          $('.new-window').css('left', x - xw);
          $('.new-window').css('top', y - yw);
        }

        $(document).mousemove( function(e) {
          if(flag){moveWindow(e);}
        });

        $('.new-window').mouseup( function() {
          $(document).off();
        });
    });

    $('.new-title').mousedown(function() {
      flag = true;

      $('.new-title').mouseup( function() {
        flag = false;
      });
    });
    });
  }
 };
})(jQuery);
