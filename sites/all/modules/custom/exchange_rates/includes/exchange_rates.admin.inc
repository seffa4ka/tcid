<?php

/**
 * @file
 * Form.
 */

/**
 * Glues form.
 *
 * @return array
 *   Form.
 */
function exchange_rates_page_forms() {

  $build['form1'] = drupal_get_form('exchange_rates_config_form');
  $build['form2'] = drupal_get_form('exchange_rates_batch_form');

  return $build;
}

/**
 * Form admin configuration.
 *
 * Felds for added new currency value: code, value, timestamp.
 */
function exchange_rates_config_form($form, &$form_state) {
  $form = array();

  $form['label'] = array(
    '#markup' => t('Add a new currency value.'),
  );

  $form['code'] = array(
    '#type' => 'textfield',
    '#title' => t('Currency code'),
    '#required' => TRUE,
    '#description' => t('Example: rub.'),
  );

  $form['value'] = array(
    '#type' => 'textfield',
    '#title' => t('Rate'),
    '#element_validate' => array('element_validate_number'),
    '#required' => TRUE,
    '#description' => t('Value.'),
  );

  $form['timestamp'] = array(
    '#type' => 'date',
    '#title' => t('Date'),
    '#required' => TRUE,
    '#description' => t('Set the date update.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#submit' => array('exchange_rates_form_rate_submit'),
  );

  return $form;
}

/**
 * Batch form.
 *
 * @return array
 *   Form.
 */
function exchange_rates_batch_form($form, &$form_state) {
  $form = array();

  $form['label'] = array(
    '#markup' => t("Mass update currency rates on today's date."),
  );

  $form['batch'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
    '#submit' => array('exchange_rates_form_batch_submit'),
  );

  return $form;
}
