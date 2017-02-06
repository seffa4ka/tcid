<?php

/**
 * @file
 * Common file.
 */

/**
 * Passes variables for js and return title and messages.
 *
 * @return array
 *   $list
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
    return theme('new_status_form', array('body' => $list));
  }
}
