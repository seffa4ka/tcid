<?php

/**
 * @file
 * Common file.
 */

/**
 * The function of forming the message box.
 *
 * Transmitted settings window: form_height, form_width, form_bg. If there is a
 * message, return $final_list.
 */
function new_status_form_get_message() {
  drupal_add_js(array(
    'new_status' => array(
      'form_height' => variable_get('form_height'),
      'form_width' => variable_get('form_width'),
      'form_bg' => variable_get('form_bg'),
    ),
  ), 'setting');

  foreach (drupal_get_messages() as $type => $messages) {
    foreach ($messages as $message) {
      $list[$type][] = $message;
    }
  }

  if (isset($list)) {
    $final_list = '';

    foreach ($list as $title => $messages) {

      if ($title === 'status') {
        $final_list .= '<div class="new-status-messages">';
        foreach ($messages as $message) {
          $final_list .= $message . '<br>';
        }
        $final_list .= '</div>';
      }

      if ($title === 'error') {
        $final_list .= '<div class="new-error-messages">';
        foreach ($messages as $message) {
          $final_list .= $message . '<br>';
        }
        $final_list .= '</div>';
      }

      if ($title === 'warning') {
        $final_list .= '<div class="new-warning-messages">';
        foreach ($messages as $message) {
          $final_list .= $message . '<br>';
        }
        $final_list .= '</div>';
      }
    }

    return theme('new_status_form', array('body' => $final_list));
  }
}
